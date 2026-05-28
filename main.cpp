#include <iostream>
#include "flatbuffers/flatbuffers.h"
#include "monster_generated.h" //Byte Array <-> Object Utility function

//using namespace flatbuffers;

int main()
{
	flatbuffers::FlatBufferBuilder builder;
	auto weapon = CreateWeaponDirect(builder, "망치", 10, Grade_unique);
	auto monster = CreateMonsterDirect(builder, "박기원", 100, 0, 0, weapon);
	builder.Finish(monster);
	const uint8_t* flatbuffer = builder.GetBufferPointer();
	//send

	//recv
	const auto 기원맨 = GetMonster(flatbuffer);

	std::cout << 기원맨->name()->c_str() << std::endl;
	std::cout << 기원맨->health() << std::endl;
	std::cout << 기원맨->mp() << std::endl;
	std::cout << 기원맨->gold() << std::endl;
	std::cout << 기원맨->weapons()->name()->c_str() << std::endl;
	std::cout << EnumNameGrade(기원맨->weapons()->grade()) << std::endl;

	return 0;
}