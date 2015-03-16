#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include"../SubSecuencia.h"
#include"../Simulador.h"
using namespace CppUnit;
using namespace std;

//-------------

class UnitTestCase : public CppUnit::TestFixture
{
   
    CPPUNIT_TEST_SUITE(UnitTestCase);
    CPPUNIT_TEST(test_subcadenaComun1);
    CPPUNIT_TEST(test_subcadenaComun2);
    CPPUNIT_TEST(test_subcadenaComun3);
    CPPUNIT_TEST_SUITE_END();
 
public:

    void setUp(void);
    void tearDown(void);

 

protected:
    void test_subcadenaComun1(void);
    void test_subcadenaComun2(void);
    void test_subcadenaComun3(void);
private:
    
	Simulador* simulador;
};
