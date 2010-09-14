/*nimh-doc
 * Project : %(Lamia)project
 * File    : %(Lamia-source)path/System/Egg/state.h
 * Licenses : %(Lamia-documentation)path/Licenses.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group
 * Created : 2009-12-07
 * Revisions :
 * + 2009-12-07 Created the File
 * ! 3176-1-35 Found out I must have been smoking crack as I wrote this file.
 * - 3176-1-35 Removed crack binge inspired code.
 * + 3176-1-35 Put some decent code in here.
 * ? 3176-1-35 kind of curious if I will look at this in a few months and think
 **            the same?
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

/*nimh-doc
 * Type: lamia_symbol
 * Member : base : lamia_object : the lamia object that owns this.
 * Member : type : nimh_string : the "type" this content has.
 * Member : payload : void : the payload of this content
 * Purpose :
 * The data that this symbol has, with its type noted.
 */
typedef struct {
    lamia_object *base;
    nimh_string *type;
    void *payload;
} lamia_symbol;

/*nimh-doc
 * Method : symbol_talbe
 * Param : nimh_book : the book Lamia is looking at
 * Purpose :
 * Initialise the symbol table that we are using here.
 */
void symbol_table(nimh_book*);

/*nimh-doc
 * Method : symbol
 * Param : nimh_book : the book Lamia is looking at
 * Param : lamia_string : the name of our object
 * Param : lamia_string : the object's type
 * Param : void : optional : nil : the new object's payload
 * Purpose :
 * Create a new symbol
 */
lamia_symbol* symbol(nimh_book*,nimh_string*,nimh_string*,void=nil);

/*nimh-doc
 * Method : symbol
 * Param : nimh_book : the book Lamia is looking at
 * Param : lamia_string : the name of the object
 * Param : void : optional : nil : give it a payload
 * Purpose :
 * Grab a symbol
 */
lamia_symbol* symbol(nimh_book*,nimh_string*,void=nil);

/*nimh-doc
 * Method : symbol
 * Param : nimb_book : the book Lamia is looking at
 * Param : lamia_string : copy to
 * Param : lamia_string : copy from
 * Purpose :
 * Copy a symbol into another
 */
lamia_symbol* symbol(nimh_book*,nimh_string*,nimh_string*);

/*nimh-doc
 * Method : symbol_smash
 * Param : nimh_book : the book Lamia is looking at
 * Param : lamia_string : the symbol to smash
 * Purpose :
 * Delete a symbol from the various interpreters.
 */
void symbol_smash(nimh_book*,nimh_string*);

#endif // __LAMIA_EGG_STATE_H__


