#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"
#include "../inc/MateriaSource.hpp"
#include "../inc/Colors.hpp"
#include <iostream>

int main() {
    std::cout << CYAN << "=== COMPLETE PROJECT TESTING ===" << RESET << std::endl;
    
    // Test 1: Exercise Required Test (from subject)
    std::cout << "\n" << YELLOW << "--- Test 1: Official Exercise Test ---" << RESET << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    
    // Test 2: MateriaSource comprehensive testing
    std::cout << "\n" << YELLOW << "--- Test 2: MateriaSource Features ---" << RESET << std::endl;
    {
        MateriaSource source;
        
        // Learn different materia types
        source.learnMateria(new Ice());
        source.learnMateria(new Cure());
        source.learnMateria(new Ice());    // Duplicate type - should work
        source.learnMateria(new Cure());   // Fill to capacity
        source.learnMateria(new Ice());    // Should be ignored (full capacity)
        
        // Test creation
        AMateria* ice1 = source.createMateria("ice");
        AMateria* cure1 = source.createMateria("cure");
        AMateria* ice2 = source.createMateria("ice");
        AMateria* unknown = source.createMateria("fire");  // Should return NULL
        
        std::cout << "Created materia types: ";
        if (ice1) std::cout << ice1->getType() << " ";
        if (cure1) std::cout << cure1->getType() << " ";
        if (ice2) std::cout << ice2->getType() << " ";
        if (!unknown) std::cout << "NULL(fire)";
        std::cout << std::endl;
        
        // Clean up created materia
        delete ice1;
        delete cure1;
        delete ice2;
    }
    
    // Test 3: Character inventory management
    std::cout << "\n" << YELLOW << "--- Test 3: Character Inventory ---" << RESET << std::endl;
    {
        Character hero("Hero");
        Character target("Target");
        
        // Fill inventory
        hero.equip(new Ice());
        hero.equip(new Cure());
        hero.equip(new Ice());
        hero.equip(new Cure());
        
        // Test full inventory
        hero.equip(new Ice());  // Should go to droplist
        
        // Use all equipped materia
        std::cout << "Using all equipped materia:" << std::endl;
        hero.use(0, target);
        hero.use(1, target);
        hero.use(2, target);
        hero.use(3, target);
        
        // Test unequipping
        hero.unequip(1);  // Remove cure
        hero.unequip(3);  // Remove cure
        
        // Try using unequipped slots
        std::cout << "\nTrying to use unequipped slots (nothing should happen):" << std::endl;
        hero.use(1, target);  // Should do nothing
        hero.use(3, target);  // Should do nothing
        
        // Re-equip in empty slots
        std::cout << "\nRe-equipping unequipped slots:" << std::endl;
        hero.equip(new Cure());  // Should go to slot 1
        hero.equip(new Cure());  // Should go to slot 3
        hero.use(1, target); // Should use cure
        hero.use(3, target); //Should use cure
    }
    
    // Test 4: Copy semantics and deep copying
    std::cout << "\n" << YELLOW << "--- Test 4: Copy Operations ---" << RESET << std::endl;
    {
        // Character copy testing
        Character original("Original");
        original.equip(new Ice());
        original.equip(new Cure());
        
        // Copy constructor
        Character copy(original);
        std::cout << "Copy name: " << copy.getName() << std::endl;
        
        // Test that copies are independent
        Character enemy("Enemy");
        original.use(0, enemy);  // Original uses ice
        copy.use(0, enemy);      // Copy uses its own ice clone
        
        // Assignment operator
        Character assigned("Assigned");
        assigned.equip(new Ice());  // Give it some materia first
        assigned = original;        // Should copy original's inventory
        std::cout << "\nAssigned name: " << assigned.getName() << std::endl;
        assigned.use(1, enemy);     // Should use copied cure
        
        // MateriaSource copy testing
        MateriaSource sourceA;
        sourceA.learnMateria(new Ice());
        sourceA.learnMateria(new Cure());
        
        MateriaSource sourceB(sourceA);  // Copy constructor
        AMateria* materia = sourceB.createMateria("ice");  // Should work
        if (materia) {
            std::cout << "\nSourceB created: " << materia->getType() << std::endl;
            delete materia;
        }
    }
    
    // Test 5: Error handling and edge cases
    std::cout << "\n" << YELLOW << "--- Test 5: Edge Cases ---" << RESET << std::endl;
    {
        Character hero("EdgeTester");
        Character target("Target");
        
        // Test invalid operations
        hero.use(5, target);     // Invalid index
        hero.use(-1, target);    // Invalid index
        hero.unequip(10);        // Invalid index
        hero.unequip(-5);        // Invalid index
        hero.equip(NULL);        // NULL materia
        
        // Test using empty slots
        hero.use(0, target);     // Empty slot, should do nothing
        hero.unequip(0);         // Empty slot, should do nothing
        
        // MateriaSource edge cases
        MateriaSource source;
        source.learnMateria(NULL);  // NULL input
        AMateria* nothing = source.createMateria("nonexistent");
        if (!nothing) {
            std::cout << "Correctly returned NULL for unknown type" << std::endl;
        }
        
        // Test empty source
        AMateria* empty = source.createMateria("ice");
        if (!empty) {
            std::cout << "Correctly returned NULL from empty source" << std::endl;
        }
    }
    
    // Test 6: Polymorphism verification
    std::cout << "\n" << YELLOW << "--- Test 6: Polymorphism ---" << RESET << std::endl;
    {
        // Create through interfaces
        IMateriaSource* source = new MateriaSource();
        ICharacter* character = new Character("Polymorphic");
        
        source->learnMateria(new Ice());
        source->learnMateria(new Cure());
        
        AMateria* materia1 = source->createMateria("ice");
        AMateria* materia2 = source->createMateria("cure");
        
        character->equip(materia1);
        character->equip(materia2);
        
        // Use through interface pointers
        ICharacter* target = new Character("PolyTarget");
        character->use(0, *target);  // Polymorphic call to Ice::use()
        character->use(1, *target);  // Polymorphic call to Cure::use()
        
        std::cout << "Polymorphic character name: " << character->getName() << std::endl;
        
        delete target;
        delete character;
        delete source;
    }
    
    // Test 7: Memory leak verification setup
    std::cout << "\n" << YELLOW << "--- Test 7: Memory Management ---" << RESET << std::endl;
    {
        std::cout << "Creating and destroying objects to test memory management..." << std::endl;
        
        // Create many objects that will test all destructors
        for (int i = 0; i < 3; i++) {
            MateriaSource* src = new MateriaSource();
            src->learnMateria(new Ice());
            src->learnMateria(new Cure());
            
            Character* char1 = new Character("TestChar1");
            Character* char2 = new Character("TestChar2");
            
            // Create and equip materia
            char1->equip(src->createMateria("ice"));
            char1->equip(src->createMateria("cure"));
            char1->equip(src->createMateria("ice"));
            
            // Test unequipping (goes to droplist)
            char1->unequip(0);
            char1->unequip(2);
            
            // Use remaining materia
            char1->use(1, *char2);
            
            // Copy operations
            Character char3(*char1);  // Copy constructor
            *char2 = char3;           // Assignment operator
            
            delete src;
            delete char1;
            delete char2;
            // char3 destructor called automatically
        }
        
    }
    
    std::cout << "\n" << CYAN << "=== ALL TESTS COMPLETED ===" << RESET << std::endl;
    
    return 0;
}
