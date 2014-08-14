#pragma once

#include "cad/interface/variantable.h"
#include "cad/interface/metatype.h"
#include "cad/const.h"

#include "cad/const.h"

#include <cmath>

namespace lc {

    /**
      * Represents a Color
      *
      */
    class Color : public MetaType {
        public:
            enum Method {
                Invalid = -1,
                ByLayer = 0,
                ByEntity = 1
            };

            /**
             * @brief Color default constructor
             */
            Color() : MetaType() , _method(Invalid), _r(0.), _g(0.), _b(0.), _a(0.) {}

            /**
             * @brief Color with specific arguments
             * @param r
             * @param g
             * @param b
             * @param a
             */
            Color(double r, double g, double b, double a = 1.) : MetaType(), _method(ByEntity), _r(r), _g(g), _b(b), _a(a)  {}
            \
            /**
             * @brief Color from other color
             * @param Color other
             */
            Color(const Color& other) : MetaType(), _method(other._method), _r(other._r), _g(other._g), _b(other._b), _a(other._a) {}

            /**
             * @brief Color from other method
             * @param Method method
             */
            Color(const Method& method) : MetaType(), _method(method), _r(0.), _g(0.), _b(0.), _a(0.) {}


            Color(Method method) {
                if (method == Invalid) {
                    throw;
                }

                if (method == ByEntity) {
                    throw;
                }

                this->_method = method;
            }

            Color& operator = (const Color& other) {
                if (this != &other) {
                    _r = other._r;
                    _g = other._g;
                    _b = other._b;
                    _a = other._a;
                    _method = other._method;
                }

                return *this;
            }

            ~Color() {
            }
            /**
             * @brief returns method
             * @return Method method
             */
            Method method() const {
                return _method;
            }

            /**
             * @brief red
             * @return
             */
            double red() const {
                return _r;
            }
            double green() const {
                return _g;
            }
            double blue() const {
                return _b;
            }
            double alpha() const {
                return _a;
            }

            short redI() const {
                return std::round(_r * 255);
            }
            short greenI() const {
                return std::round(_g * 255);
            }
            short blueI() const {
                return std::round(_b * 255);
            }
            short alphaI() const {
                return std::round(_a * 255);
            }

            bool variantValid() const {
                return !(_method == Invalid);
            }

            metaTypeId metaName() const {
                return MetaType::COLOR;
            }

        private:
            Method _method;
            double _r;
            double _g;
            double _b;
            double _a;
    };


}

// Color_H
