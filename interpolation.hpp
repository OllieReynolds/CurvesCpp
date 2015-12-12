#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

namespace OMath {
	template<typename T> class Interpolation {
	public:
		////////////////////////////////////////////////////////////////////
		/// https://en.wikipedia.org/wiki/Linear_interpolation
		/// Params:
		/// a --> Start
		/// b --> End
		/// t --> Position - Range:(0-1) 
		/// Output:
		/// T --> Interpolated value
		////////////////////////////////////////////////////////////////////
		static T Linear(T a, T b, float t) {
			return (1 - t) * a + t * b;
		}
	};
}

#endif // INTERPOLATION_HPP
