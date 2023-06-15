add_executable (Test test.c)

add_executable (FileTest dirTest.c)

target_compile_options(FileTest PRIVATE -g)
target_link_libraries(FileTest cjson)

add_test(NAME MyDirTest
	COMMAND FileTest)

add_test(NAME MyTest
	COMMAND Test)
