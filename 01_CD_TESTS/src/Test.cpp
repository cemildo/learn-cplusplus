#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "sayHello.h"

/*
 * in order to create test you need to have static library
 * Just create a static library and copy your files in that static library
 * you need to compile it.
 *
 * create a cute static library test suite
 * make sure you include the static library project in to that
 * then set the path and symbols
 * make sure you select c++ then
 * check includes libraries and library path( select xxxx.a file under debug folder)
 * and resources
 * then include your header file from that library and you are ready to implement
 * your tests.
 * */
void testSayHello(){
	std::ostringstream os{"cemil"};
	sayHello(os);
	ASSERT_EQUAL("cemil", os.str());
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(testSayHello));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}
