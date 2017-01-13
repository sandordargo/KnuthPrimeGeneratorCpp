#include <fstream>

#include <gtest/gtest.h>

#include <PrimePrinter.h>

TEST(PrimePrinterTest, MakeSureOutputMatchesGold) {
    std::ofstream out("lead");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    PrimePrinter primePrinter;
    primePrinter.print();
    out.close();

    std::ifstream goldFile("gold");
    std::ifstream leadFile("lead");

    std::string goldLine;
    std::string leadLine;
    while (std::getline(goldFile, goldLine)) {
      std::getline(leadFile, leadLine);
      ASSERT_EQ(goldLine, leadLine);
    }

    ASSERT_FALSE(std::getline(leadFile, leadLine));


    remove("lead");
    std::cout.rdbuf(coutbuf);
}