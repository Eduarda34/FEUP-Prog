//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        /*!
         * largura da imagem
         */
        int iwidth;
        /*!
         *altura da imagem
         */
        int iheight;
        /*!
         *pixeis da imagem, uma matriz de cores implementada como array de apontadores
         */
        color **pixels;
    public:
        /*!
         *
         * @param w = largura da imagem
         * @param h = altura da imagem
         * @param fill = cor que vai ter todos os pixeis
         */
        image(int w, int h, const color& fill = color::WHITE);
        /*!
         *Destructor. Deve libertar o espaço alocado para a matriz de pixeis
         */
        ~image();
        /*!
         *
         * @return largura da imagem
         */
        int width() const;
        /*!
         *
         * @return altura da imagem
         */
        int height() const;
        /*!
         *Obtém a constante para cor do pixel na posição (x,y) para 0≤x<width() e 0≤y<height()
         * @param x = coordenadas das linhas do pixel
         * @param y = coordenadas das colunas do pixel
         * @return o valor do pixel das das coordenadas (x,y)
         */
        color& at(int x, int y);
        /*!
         *Obtém a referência mutável para cor do pixel na posição (x,y) para 0≤x<width() e 0≤y<height()
         * @param x = coordenadas das linhas do pixel
         * @param y = coordenadas das colunas do pixel
         * @return a referencia mutável  do pixel das das coordenadas (x,y)
         */
        const color& at(int x, int y) const;
        /*!
         *inverte todos os pixeis
         */
        void invert();
        /*!
         *Converte todos os píxeis para uma escala de cinzento
         */
        void to_gray_scale();
        /*!
         *vai substituir a cor a pela cor b na imagem
         * @param a = cor que tem na imagem
         * @param b = cor que vai ser substituída
         */
        void replace(const color& a, const color& b);
        /*!
         *Define a cor c para todos os pixeis com coordenadas (x′,y′) tais que x≤x′<x+w e y≤y′<y+h.
         * @param x = coordenadas linhas
         * @param y = coordenas colunas
         * @param w = largura da imagem que vamos substituir a cor
         * @param h = altura da imagem que vamos suubstituir a cor
         * @param c = cor que vai ter na imagem
         */
        void fill(int x, int y, int w, int h, const color& c);
        /*!
         *Altera imagem, misturando cada pixel com o pixel correspondente em img com factor f
         * @param img = A imagem que vamos usar com o factor
         * @param factor = Factor que vaoms misturar com os pixeis da img.
         */
        void mix(const image& img, int factor);
        /*!
         *Reduz a imagem (alterando sua dimensão) ao rectângulo com o topo superior esquerdo (x,y) e dimensão w × h.
         * @param x = coordenada das linhas do pixel superior esquerdo da imagem recortada
         * @param y = coordenada das colunas do pixel superior esquerdo da imagem recortada
         * @param w = largura da imagem recortada
         * @param h = altura da imagem recortada
         */
        void crop(int x, int y, int w, int h);
        /*!
         * roda imagem para esquerda
         */
        void rotate_left();
        /*!
         * roda imagem para direita
         */
        void rotate_right();
        /*!
         *Adiciona o conteúdo de img, substituindo os actuais pixeis a partir da posição (x,y) excepto para pixeis em img que tiverem cor neutral
         * @param img = a imagem que vamos adicionar
         * @param neutral = a cor dos pixeis da imagem img que não vai para imagem original
         * @param x = coordenadas das linhas que vamos começar alterar a imagem original
         * @param y = coordenadas das colunas que vamos começar alterar a imagem original
         */
        void add(const image& img, const color& neutral,int x, int y);
    };
}


#endif
