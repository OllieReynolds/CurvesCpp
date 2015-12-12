/*
The MIT License (MIT)

Copyright (c) 2015 Ollie Reynolds

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef CURVES_HPP
#define CURVES_HPP

#include <tuple>

////////////////////////////////////////////////////
/// Generate points along various geometric paths.
/// Params:
/// t --> time
/// w --> max width
/// h --> max height
/// Output:
/// vec2 --> x,y plot
////////////////////////////////////////////////////
namespace OMath {
	template<typename T> class Curves {
	private:
		using vec2 = std::tuple<T, T>;

	public:
		/// Bicorn Curve: http://paulbourke.net/geometry/bicorn/
		static vec2 Bicorn(T t, T w, T h) {
			float x = (w / 2) * sin(t) + (w / 2);
			float y = (h / 2) * pow(cos(t), 2) * (2 + cos(t)) / (3 + pow(sin(t), 2));
			return std::make_tuple(x, y);
		}

		/// Kappa Curve: http://paulbourke.net/geometry/kappa/
		static vec2 Kappa(T t, T w, T h) {
			float x = (w / 2) * pow(cos(t), 2) / sin(t) + (w / 2);
			float y = (h / 2) * cos(t) + (h / 2);
			return std::make_tuple(x, y);
		}

		/// Bow Curve: http://paulbourke.net/geometry/bow2d/
		static vec2 Bow(T t, T w, T h) {
			float a = 1 - pow(tan(t), 2);
			float x = (w / 2) * a * cos(t) + (w / 2);
			float y = (h / 2) * a * sin(t) + (h / 2);
			return std::make_tuple(x, y);
		}

		/// Diamond: http://paulbourke.net/geometry/diamond/
		static vec2 Diamond(T t, T w, T h) {
			float x = (w / 2) * cos(t) * sqrtf(pow(cos(t), 2)) + (w / 2);
			float y = (h / 2) * sin(t) * sqrtf(pow(sin(t), 2)) + (h / 2);
			return std::make_tuple(x, y);
		}

		/// Chrysanthemum: http://paulbourke.net/geometry/chrysanthemum/
		static vec2 Chrysanthemum(T t, T w, T h) {
			float r = 5 * (1 + sin(11 * t / 5)) - 4 * pow(sin(17 * t / 3), 4) * pow(sin(2 * cos(3 * t) - 28 * t), 8);
			float x = (w / 20) * r * cos(t) + (w / 2);
			float y = (h / 20) * r * sin(t) + (h / 2);
			return std::make_tuple(x, y);
		}

		/// Butterfly: http://paulbourke.net/geometry/butterfly/
		static vec2 Butterfly(T t, T w, T h) {
			float r = exp(cos(t)) - 2 * cos(4 * t) - pow(sin(t / 12), 5);
			float x = (w / 2) * r * cos(t) + (w / 2);
			float y = (h / 2) * r * sin(t) + (h / 2);
			return std::make_tuple(x, y);
		}
	};
}

#endif // CURVES_HPP