/*
 * HashTable.h
 *
 *  Created on: Mar 1, 2011
 *      Author: ricardorodriguez
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

namespace Sabiduria {

namespace Structures {

//////////////////////////////////////////////////////////////////////////////////////////////////////
// All objects will extend HashEntry, in order to be properly inserted into the respective hash table
class HashEntry {

public:
	virtual ~HashEntry();

	// Get the hash for this respective object
	virtual int GetHash() = 0;

private:
	HashEntry(HashEntry &); // Always enforce HashEntry is sent as references
	HashEntry() {}          // Don't allow others to instantiate

	int hashEntry;          // The hash value to use in placing a hash entry

};

//////////////////////////////////////////////////////////////////////////////////////////////////////
class HashTable {
public:
	HashTable();
	virtual ~HashTable();

	// Insert a HashEntry into the the HashTable
	// @param value - represents the HashEntry to place in the hash table
	// @return bool representing successful insertion of HashEntry
	bool Insert(HashEntry &value);

	// Retrieves a HashEntry, given the respective hash value
	// @param hashValue - representing the hash value of a respective HashEntry
	// @return HashEntry one is seeking
	HashEntry& Retrieve(int hashValue);

private:
	HashEntry *_hashArray;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
}

}

#endif /* HASHTABLE_H_ */
