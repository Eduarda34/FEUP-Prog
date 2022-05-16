
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        /*!
         * Serve para ler os atributos de fill a chamar função fill implementada no image.cpp
         */
        void fill();
        /*!
         * Inicializa imagem de um ficheiro
         */
        void open();
        /*!
         * Inicializa uma imagem com dimensões w × h e cor inicial (r,g,b) para todos os pixeis
         */
        void blank();
        /*!
         * Salva imagem para um ficheiro
         */
        void save();
    public:
        /*!
         * @param filename = O nome do ficheiro que queremos modificar
         */
        script(const std::string& filename);
        /*!
         * Destructor. Deve libertar o espaço alocado para a imagem
         */
        ~script();
        /*!
         * Para analisar o comando que demos como input
         */
        void process();

    private:
        /*!
         * Imagem que vamos alterar
         */
        image* img;
        /*!
         * As instruções que vamos dar na linha de comandos
         */
        std::ifstream input;
        /*!
         * Indica se a imagem é um output ou um input
         */
        std::string root_path;
    };
}
#endif
