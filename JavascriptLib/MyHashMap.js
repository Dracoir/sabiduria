 //Represents a basic HashMap structure

/**
 * Constructor that takes no arguments
 */
function MyHashMap() {
	this.initializeClassVariables();
}

/**
 * Initializes the class member variables
 */
MyHashMap.prototype.initializeClassVariables = function() {
	// Used as a secondary structure, to help iterate over map
	this.arrayList = [];
	// Primary structure, used to store key/value pairs
	this.myHashMap = {};
};

/**
 * Retrieves a value in the hash map, represented by the respective key
 * @param key Object representing the object in the mapping
 * @returns Object represented by the key parameter
 */
MyHashMap.prototype.get = function(key) {
	return this.myHashMap[key];
};

/**
 * Places key/value pair in mapping
 * @param key Object representing the key to use
 * @param value Object representing the value to hold
 */
MyHashMap.prototype.put = function (key,value) {
	if(key in this.myHashMap) {
		this.myHashMap[key] = value;
	} else {
		// Otherise, add a new entry
		this.arrayList.push(key);
		this.myHashMap[key] = value;
	}
};

/**
 * Removes a respective value from the map, given its key
 * @param key Object representing the value
 */
MyHashMap.prototype.remove = function(key) {
	var index = this.arrayList.indexOf(key);
	if(index == -1) {
		throw new Error('key does not exist');
	}
	this.arrayList.splice(index,1);
	delete this.myHashMap[key];
};

/**
 * Iterates through each key/value pairing, sending it
 * to the respective function
 */
MyHashMap.prototype.forEach = function(func) {
	var key, value;
	var mapLength = this.arrayList.length;
	for(var i = 0; i < mapLength; i++) {
		key = this.arrayList[i];
		value = this.myHashMap[key];
		func(key,value);
	}
};

