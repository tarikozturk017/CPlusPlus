
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {


	struct PostalCode {
		char* code;
		int population;
	};
	void sortPostCodes();
	bool load(const char filename[]);
	//newf
	bool load(PostalCode& post);
	//newf
	void display(const PostalCode& code);
	void display();
	void deallocateMemory();

}
#endif
