/*hashtable*/
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

typedef struct{
	void *value;
	unsigned short len;
	unsigned char name[1];
	
}hash_elt_t;


typedef struct{
	hash_elt_t **buckets;
	unsigned int size;
}hash_t;


typedef struct{
	char *key;
	unsigned int key_hash;
	void *value;
}hash_key_t;

#endif

