/*nimh-doc
 * Project : %(Lamia)project
 * File : %(Lamia-Source)path/Lamia/types.h
 * License : %(Lamia-Documentation)path/License.txt
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group
 * Createtd : 2009-10-07
 * Revision :
 * + 2009-10-07 Initial Creation of Lamia Egg Types
 * + 3176-1-35 Fixed the lamia_object base object.
 * + 3176-1-35 Added lamia_list object
 * + 3176-1-35 Added lamia_lids object
 * TODO:
 * * nil
 * Purpose :
 * Just some minor typedefs used in Lamia
 */

#ifndef __LAMIA_TYPES_H__
#define __LAMIA_TYPES_H__

/*nimh-doc
 * Type : lamia_object
 * Member : lid : nimh_word : unique lamia identifier
 * Member : name : nimh_string : a collequial name to go by
 * Member : created :  nimh_time : object creation time.
 * Member : accessed : nimh_time : object's last access
 * Member : expires : nimh_time : when it will start pining for fjords.
 * Member : child : void : points to the object that uses this base for it.
 * Member : next : void : points to the next lamia object we know of
 * Member : prev : void : points to the previous lamia object we know of
 * Description :
 * Basic Lamia Object. Basic functionality can be done on this, based on 
 * everything else in here. If something is appearing in too many objects, 
 * I pull it into here.
 */
typedef struct {
    nimh_word* lid;
    nimh_string* name;
    nimh_time created, accessed, expires;
    void *child, *next, *prev;
    const boolean is_lamia_object = true;
} lamia_object_data lamia_object;

/*nimh-doc
 * Type : lamia_list
 * Description :
 * Just a type cast of nimh_data type. Nothing special here.
 */
typedef nimh_data lamia_list;
typedef nimh_stack lids;

/*nimh-doc
 * Function : gen_lid
 * Param : nimh_book : the nimh_book that this Lamia is reading from.
 * Param : boolean : optional : false : whether this is a dry run.
 * Return : nimh_word : the random generated id
 * Purpose :
 * Generate a unique lid. Randomly generates it--so as to enhance 
 * security.
 */
nimh_word gen_lid(nimh_book*, boolean=false);

/*nimh-doc
 * Function : add_lid
 * Param : nimh_book : the nimh_book that this Lamia is reading from.
 * Param : nimh_word : the lid we are adding to keep track of
 * Purpose :
 * Add a unique lid into the system.
 */
void add_lid(nimh_book*, nimh_word);

/*nimh-doc
 * Function : deathnote
 * Param : nimh_book : the nimh book that this object is listed in.
 * Param : nimh_word/nimh_string : an identifier of the object to kill
 * Param : boolean : optional : false : kill it now.
 * Purpose :
 * If locked, send a time out on the lock signal--for the systems typical
 * expire time. A function is started to no longer allow its access time 
 * to be updated.
 * 
 * In the case that it is to be killed now, a flag can be set that smashes 
 * the lock and kills this object, in the nimh_book Lamia holds.
 */
void deathnote(nimh_book*, nimh_word, boolean=false);
void deathnote(nimh_book*, nimh_string, boolean=false);

/*nimh-doc
 * Function : grope_lamia
 * Param : nimh_book : the book this lamia is reading from
 * Param : nimh_word : unique id number
 * Return : lamia_object
 * Purpose:
 * grab the Lamia object we want, based on the unique id it has.
 * Aside:
 * Name changed to something slightly more amusing
 */
lamia_object grope_lamia(nimh_book*,nimh_word);

/*nimh-doc
 * Function : grab_by_lid
 * Param : nimh_book : the book this lamia is reading from
 * Param : nimh_string : a string to loosely match based on.
 * Return : lamia_list
 * Purpose :
 * Grab a series of Lamia objects we think we may want. Since asking based 
 * on a string is more than likely to get multiple results, we return a 
 * list of them. Since we are likely to get multiple of these, may as well 
 * have matching be fuzzy.
 * Aside:
 * Name changed to something slightly more amusing
 */
lamia_list grope_lamia(nimh_book*,nimh_string);

#endif // __LAMIA_TYPES_H__

