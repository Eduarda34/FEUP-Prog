#include <rgb/image.hpp>

namespace rgb {
    image::image(int w, int h, const color &fill) {
        assert(w > 0 && h > 0);
        iwidth = w;
        iheight = h;
        pixels = new color *[iwidth];
        color *data = new color[iwidth * iheight];
        for (int i = 0; i < iwidth; i++) {
            pixels[i] = data + i * iheight;
            for (int j = 0; j < iheight; j++) {
                pixels[i][j] = fill;
            }
        }
    }

    image::~image() {
        delete[]pixels[0];
        delete[]pixels;


    }

    int image::width() const {
        return iwidth;
    }

    int image::height() const {

        return iheight;


    }

    color &image::at(int x, int y) {
        return pixels[x][y];
    }

    const color &image::at(int x, int y) const {
        return pixels[x][y];
    }

    void image::invert() {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                pixels[i][j].invert();
            }
        }

    }

    void image::to_gray_scale() {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                pixels[i][j].to_gray_scale();
            }
        }

    }

    void image::fill(int x, int y, int w, int h, const color &c) {
        for (int i = 0; i < x + w; i++) {
            for (int j = 0; j < y + h; j++) {
                if (i >= x && j >= y) {
                    pixels[i][j]= c;

                }
            }
        }
    }

    void image::replace(const color &a, const color &b) {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                if (pixels[i][j] == a) {
                    pixels[i][j] = b;
                }
            }
        }
    }

    void image::add(const image &img, const color &neutral, int x, int y) {

        for (int i = 0; i <iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                if ((i >= x) && (j >= y)) {
                    if(i-x<img.iwidth && j-y<img.iheight) {
                        if (img.at(i - x, j - y) != neutral) {
                            this->pixels[i][j] = img.pixels[i - x][j - y];
                        }
                    }
                }
            }
        }
    }

    void image::crop(int x, int y, int w, int h) {

        color **newpixel = new color *[w];
        color *newdata = new color[w * h];
        for (int i = 0; i < w; i++) {
            newpixel[i] = newdata + i * h;
            for(int j=0;j<h;j++){
                    newpixel[i][j] = pixels[i+x][j+y];

            }
        }
        iheight=h;
        iwidth=w;
        delete []pixels[0];
        delete []pixels;
        pixels=newpixel;


    }

    void image::rotate_right() {
        color **newpixel = new color *[iheight];
        color *newdata = new color[iheight * iwidth];
        for (int w = 0; w < iheight; w++) {
            newpixel[w] = newdata + w * iwidth;
            for(int z=0;z<iwidth;z++){
                newpixel[w][z] = pixels[z][iheight-w-1];

            }
        }
        int x=iheight;
        iheight=iwidth;
        iwidth=x;
        delete []pixels[0];
        delete []pixels;
        pixels=newpixel;

        }

    void image::rotate_left() {
        color **newpixel = new color *[iheight];
        color *newdata = new color[iheight * iwidth];
        for (int w = 0; w < iheight; w++) {
            newpixel[w] = newdata + w * iwidth;
            for(int z=0;z<iwidth;z++){
                newpixel[w][z] = pixels[iwidth-z-1][w];

            }
        }
        int x=iheight;
        iheight=iwidth;
        iwidth=x;
        delete []pixels[0];
        delete []pixels;
        pixels=newpixel;

    }

    void image::mix(const image &img, int factor) {
        for (int i = 0; i < iwidth; i++) {
            for (int j = 0; j < iheight; j++) {
                pixels[i][j].mix(img.pixels[i][j], factor);
            }
        }
    }
}
