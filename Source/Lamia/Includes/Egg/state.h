/*nimhdoc
 * Project : %(Lamia)project
 * File    : %(Lamia-source)path/System/Egg/state.h
 * Licenses : %(Lamia-documentation)path/Licenses.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group
 * Created : 2009-12-07
 * Revisions :
 * 2009-12-07 Created the File
 * TODO:
 * * nil
 * Purpose :
 * General purpose state variable holding section. This datatype is to 
 * contain most of the variables used with the various Lamia scripting 
 * systems (Lua, Lisp, Haskal, Perl, Python, Ruby, ECMAScript... and 
 * maybe Intercal)
 */

#ifndef __LAMIA_EGG_STATE_H__
#define __LAMIA_EGG_STATE_H__

typedef struct {
    lamia_identifier identifier;
    lamia_count index;
    lamia_storage *current;
} lamia_lookup;

typedef struct {
    lamia_count index;
    lamia_object *contents;
    lamia_storage *prev;
    lamia_storage *next;
} lamia_storage;

lamia_storage create_egg_state();
lamia_lookup* create_lamia_lookup(*lamia_storage);
lamia_lookup* add_back(lamia_lookup, *lamia_storage);
lamia_lookup* add_front(lamia_lookup, *lamia_storage);

#endif // __LAMIA_EGG_STATE_H__


