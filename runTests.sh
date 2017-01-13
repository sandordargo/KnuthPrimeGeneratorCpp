#!/bin/sh

bms build -b && (bms test --bin-options "--gtest_color=yes" ; cat test/logs/toolchain_v2_static_debug/unittest/unittest.log)