#include <iostream>
#include "flatbuffers/flatbuffers.h"
#include "monster_generated.h" //Byte Array <-> Object Utility function

//using namespace flatbuffers;

int main()
{
	flatbuffers::FlatBufferBuilder builder;
	// 직렬화
	auto monster = CreateMonsterDirect(builder, "몬몬이", 100, 100, 50000, 77, 4, "knife");
	builder.Finish(monster);
	const uint8_t* flatbuffer = builder.GetBufferPointer();
	//send

	//recv
	// 역직렬화
	const auto snowman = GetMonster(flatbuffer);
	// 역직렬화한 것 출력
	std::cout << snowman->name()->c_str() << std::endl;
	std::cout << snowman->health() << std::endl;
	std::cout << snowman->mp() << std::endl;
	std::cout << snowman->exp() << std::endl;
	std::cout << snowman->gold() << std::endl;
	std::cout << snowman->level() << std::endl;
	std::cout << snowman->weapon()->c_str() << std::endl;

	return 0;
}