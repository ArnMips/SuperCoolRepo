#include <gtest/gtest.h>

#include "tst_arabictoroman.h"
#include "tst_romantoarabic.h"
#include "tst_asciitoint.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
