#ifndef ROMANH
#define ROMANH
// Roman.h - Roman class

namespace Anderson_Software_Group {
	const int Roman_max = 20;
	class Roman {
	private:
		int value;										// decimal value
		char s[Roman_max];							// Roman String
		void convert_Roman(); 						// convert to Roman string
	public:
	 // Constructors
		Roman(int n = 1) { value = n; convert_Roman(); }
	 // Member Functions
		const char *getroman() const { return s; }
		int getnum() const { return value; }
	};
}
#endif
