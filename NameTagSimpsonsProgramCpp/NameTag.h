#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H
namespace sdds {
	class NameTag {
	public:	
		char* name[51];
		void set(const char* name);
	};
}
#endif
