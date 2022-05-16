
#include <iostream>
#include <fstream>

#include <rgb/script.hpp>
#include <png/png.hpp>
#include <cstring>
#include <sstream>


namespace rgb {
    std::istream &operator>>(std::istream &input, color &c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    script::script(const std::string &filename) :
            img(NULL), input(filename), root_path(ROOT_PROJ_DIR) {

    }

    script::~script() {
        if (img != NULL) {
            delete img;
        }
    }

    void script::process() {
        while (!input.eof()) {
            std::string command;
            input >> command;
            if (command.empty()) {
                break;
            }
            std::cout << "Executing command '" << command << "' ..." << std::endl;

            if (command == "open") {
                open();
            } else if (command == "blank") {
                blank();
            }

            // Other commands
            if (img == NULL) {
                std::cout << "No image loaded! Stopping ..." << std::endl;
                break;
            }

            if (command == "save") {
                save();
            } else if (command == "fill") {
                fill();
            } else if (command == "invert") {
                img->invert();

            } else if (command == "to_gray_scale") {
                img->to_gray_scale();
            } else if (command == "rotate_left") {
                img->rotate_left();

            } else if (command == "rotate_right") {
               img->rotate_right();
            }else if (command== "replace") {
                color c;
                color d;
                input >>c>>d;
                img->replace(c,d);


            }else if (command == "crop") {
                int x;
                int y;
                int w;
                int h;
                input>>x>>y>>w>>h;
                img->crop(x,y,w,h);

            } else if (command == "mix") {
                std::string filename;
                input >> filename;
                image *imagem;
               imagem = png::load(root_path + "/" + filename);
               int f;
               input>>f;
               img->mix(*imagem,f);


            } else if (command == "add") {
                std::string filename;
                input >> filename;
                image *imagem;
                imagem = png::load(root_path + "/" + filename);
                color c;
                int x;
                int y;
                input>>c >>x>>y;
               img->add(*imagem,c,x,y);

            }
            // TODO ...

        }
    }

    void script::open() {
        if (img != NULL) {
            // Delete previous image
            delete img;
        }
        std::string filename;
        input >> filename;
        img = png::load(root_path + "/" + filename);
    }

    void script::blank() {
        if (img != NULL) {
            // Delete previous image
            delete img;
        }
        int w, h;
        color c;
        input >> w >> h >> c;
        img = new image(w, h, c);
    }

    void script::save() {
        std::string filename;
        input >> filename;
        png::save(root_path + "/" + filename, img);
    }

    void script::fill() {
        int x, y, w, h;
        color c;
        input >> x >> y >> w >> h >> c;
        img->fill(x, y, w, h, c);
    }
}
