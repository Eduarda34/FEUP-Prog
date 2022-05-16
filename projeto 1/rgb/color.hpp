//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
        /*!
         * Campo membro para representar a componente RGB neste caso R de red;
         */
        rgb_value r;
        /*!
         * Campo membro para representar a componente RGB neste caso G de green;
         */
        rgb_value g;
        /*!
         * Campo membro para representar a componente RGB neste caso B de blue;
         */
        rgb_value b;
    public:
        /*!
         *  Constante para cor Vermelha
         */
        static const color RED;
        /*!
         *  Constante para cor Verde
         */
        static const color GREEN;
        /*!
         *  Constante para cor Azul
         */
        static const color BLUE;
        /*!
         *  Constante para cor Preta
         */
        static const color BLACK;
        /*!
         *  Constante para cor Branca
         */
        static const color WHITE;
        /*!
         * Construtor que inicializa as componentes RGB a 0.
         */
        color();
        /*!
         *
         * @param c= A cor que recebe e que vai dar valor á color do construtor
         */
        color(const color &c);
        /*!
         * Construtor que usa valores fornecidos para inicializar components RGB.
         */

        color(rgb_value r, rgb_value g, rgb_value b);
         /*!
          *
          * @return Obtêm valor de r
          */
        rgb_value red() const;
        /*!
         *
         * @return Obtêm referência de r
         */
        rgb_value& red();
        /*!
         *
         * @return Obtêm valor de g
         */
        rgb_value green() const;
        /*!
         *
         * @return Obtêm referência de g
         */
        rgb_value& green();
        /*!
         *
         * @return Obtêm valor de b
         */
        rgb_value blue() const;
        /*!
         *
         * @return Obtêm referência de b
         */
        rgb_value& blue();
        /*!
         * Atribui os valores de RGB da color c
         * @param c = Atribui os valores da color c á classe
         * @return os r da color c,g da color c e o b da color c
         */
        color& operator=(const color&c);
        /*!
         *
         * @param c = A cor que vamos comparar com a cor da classe
         * @return true se as duas cores forem iguais ou false se não forem
         */
        bool operator==(const color &c) const;
        /*!
         * Operador de comparaçao entre duas cores
         * @param c = cor que recebe
         * @return se c for igual á cor do construtor devolve true se não devolve false
         */
        bool operator!=(const color &c) const;
/*!
 * Inverte a cor
 * r=255-r
 * g=255-g
 * b=255-b
 */
        void invert();
        /*!
         *  A função to_gray_scale passa o pixels para uma escala de cinzentos
         * r=(r+g+b)/3
         * g=(r+g+b)/3
         * b=(r+g+b+)/3
         */


        void to_gray_scale();

        /*!
         * A função mix recebe uma cor c e um fator f.
         * Esta função mistura a cor que demos na função com o fator f entre 0 a 100
         * O r=m(r,c.r),g=m(g,c.g),b=m(b,c.b)
         * Onde o m(a,b)=(100-f)a+fb)/100
         * @param c = A cor que recebe
         * @param f= Factor entre 0 100 que vamos misturar com c
         */
        void mix(const color& c, int f);
    };
}
#endif
