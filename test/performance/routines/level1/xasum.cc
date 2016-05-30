
// =================================================================================================
// This file is part of the CLBlast project. The project is licensed under Apache Version 2.0. This
// project loosely follows the Google C++ styleguide and uses a tab-size of two spaces and a max-
// width of 100 characters per line.
//
// Author(s):
//   Cedric Nugteren <www.cedricnugteren.nl>
//
// =================================================================================================

#include "performance/client.h"
#include "routines/level1/xasum.h"

// Shortcuts to the clblast namespace
using float2 = clblast::float2;
using double2 = clblast::double2;

// Main function (not within the clblast namespace)
int main(int argc, char *argv[]) {
  switch(clblast::GetPrecision(argc, argv, clblast::Precision::kSingle)) {
    case clblast::Precision::kHalf:
      clblast::RunClient<clblast::TestXasum<half>, half, half>(argc, argv); break;
    case clblast::Precision::kSingle:
      clblast::RunClient<clblast::TestXasum<float>, float, float>(argc, argv); break;
    case clblast::Precision::kDouble:
      clblast::RunClient<clblast::TestXasum<double>, double, double>(argc, argv); break;
    case clblast::Precision::kComplexSingle:
      clblast::RunClient<clblast::TestXasum<float2>, float2, float2>(argc, argv); break;
    case clblast::Precision::kComplexDouble:
      clblast::RunClient<clblast::TestXasum<double2>, double2, double2>(argc, argv); break;
  }
  return 0;
}

// =================================================================================================
