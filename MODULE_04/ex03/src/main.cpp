#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

// Extra Materia to verify support for ANY AMateria in Character and MateriaSource
class Thunder : public AMateria {
public:
	Thunder(): AMateria("thunder") {}
	Thunder(const Thunder& other): AMateria(other) {}
	Thunder& operator=(const Thunder& other) { if (this != &other) this->_type = other._type; return *this; }
	virtual ~Thunder() {}
	AMateria* clone() const { return new Thunder(*this); }
	void use(ICharacter& target) { std::cout << "* strikes " << target.getName() << " with thunder *" << std::endl; }
};

int main()
{
	std::cout << "\n" << WHITE << "==================== SUBJECT BASE TEST ====================" << RESET << "\n";

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << WHITE << "\n-------------------- ADDITIONAL TESTS ---------------------" << RESET << "\n\n";

/*============ Keep track of materias we must delete manually later =============*/
	AMateria* extraKeep = 0;   // not equipped due to full inventory
	AMateria* keptAfterUnequip = 0; // unequipped from a character

/*============ Test 1: Inventory capacity and invalid indices (reuse src, create one extra character) =============*/
	std::cout << CYAN << "=====[Test 1] Inventory capacity and invalid index" << RESET << "\n";
	{
		Character alice("alice");
		AMateria* m0 = src->createMateria("ice");
		AMateria* m1 = src->createMateria("cure");
		AMateria* m2 = src->createMateria("ice");
		AMateria* m3 = src->createMateria("cure");
		extraKeep = src->createMateria("ice");

		alice.equip(m0);
		alice.equip(m1);
		alice.equip(m2);
		alice.equip(m3);
		bob->equip(m0->clone());
		bob->equip(m1->clone());
		alice.equip(extraKeep);//does nothing, no segfault


		alice.use(0, *bob);
		alice.use(1, *bob);
		alice.use(2, *bob);
		alice.use(3, *bob);
		bob->use(0, alice);
		bob->use(1, alice);
		alice.use(-1, *bob);// does nothing, no segfault
		alice.use(42, *bob);// does nothing, no segfault

		alice.unequip(0);
		/*delete to avoid leaks, once unequiped, the materia
		is still allocated but dosen't belong to a Character to delete with it*/
		delete m0;
		std::cout << YELLOW << "\ncalling destructors for [Test 1]" << RESET << "\n";
	}
	std::cout << CYAN << "end of [Test 1]====" << RESET << "\n";
	std::cout << "\n";

/*============ Test 2: unequip must NOT delete Materia (reuse 'me') =============*/
	std::cout << CYAN << "====[Test 2] unequip does NOT delete Materia" << RESET << "\n";
	{
		keptAfterUnequip = src->createMateria("ice");
		// 'me' currently has 2 materias in slots 0 and 1; next equip goes to slot 2
		me->equip(keptAfterUnequip);
		me->unequip(2); // release ownership; we must delete later
		keptAfterUnequip->use(*bob);// if the materia has not been delete, this should print ice msg

		std::cout << YELLOW << "\ncalling destructors for [Test 2]" << RESET << "\n";
	}
	std::cout << CYAN << "end of [Test 2]==== " << RESET << "\n";
	std::cout << "\n";

/*============ Test 3: Character deep copy and assignment (verify deep behavior) =============*/
	std::cout << CYAN << "====[Test 3] Character deep copy and assignment" << RESET << "\n";
	Character* copyPtr = 0;
	{
		Character	orig("orig");
		AMateria	*thunder = new Thunder();
		orig.equip(thunder);
		// orig.equip(src->createMateria("cure"));
		copyPtr = new Character(orig); // deep copy
		// 'orig' is destroyed at the end of this scope on purpose for this test
	}
	// Use the copy after original is destroyed
	copyPtr->use(0, *bob);
	copyPtr->use(1, *bob);

	Character assigned("assigned");
	assigned = *copyPtr; // deep assignment
	assigned.use(0, *bob);

	std::cout << '\n';

	delete copyPtr;
	assigned.use(0, *bob); // should still work

	std::cout << CYAN << "end of [Test 3]====" << RESET << "\n";
	std::cout << "\n";

/*============ Test 4: MateriaSource returns 0 for unknown type (reuse src) =============*/
	std::cout << CYAN << "====[Test 4] MateriaSource unknown type -> returns null" << RESET << "\n";
	{
		AMateria* unknown = src->createMateria("fire");
		if (!unknown)
			std::cout << "(unknown materia type returns null)" << std::endl;

		std::cout << CYAN << "end of [Test 4]==== " << RESET << "\n";
		std::cout << "\n";
	}

/*============ Test 5: Support ANY AMateria via Thunder (reuse src and me) =============*/
	std::cout << CYAN << "====[Test 5] Support ANY AMateria (Thunder)" << RESET << "\n";
	src->learnMateria(new Thunder());
	{
		AMateria* t = src->createMateria("thunder");
		// 'me' slots: 0 ice, 1 cure, 2 is free after Test 2, 3 free
		me->equip(t);
		me->use(2, *bob);

		std::cout << CYAN << "end of [Test 5]====" << RESET << "\n";
		std::cout << "\n";
	}

	std::cout << WHITE << "-------------------- BEGIN DESTRUCTION --------------------" << RESET << "\n\n";
/*============ Manual clean-up for resources not owned by characters/sources =============*/
	delete extraKeep;        // was never equipped (Test 1)
	delete keptAfterUnequip; // was unequipped (Test 2)
	delete bob;
	delete me;
	delete src;

	return 0;
}
