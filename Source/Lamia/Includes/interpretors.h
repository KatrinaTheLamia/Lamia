/*nimh-doc
 * Project : %(Lamia)project
 * File    : %(Lamia-source)path/Lamia/interpretors.h
 * Authors : %(KatrinaTheLamia)author
 * Groups  : %(NIMHLabs)group
 * License : %(Lamia-doc)path/License.txt
 * Created : 3145-5-64
 * Revisions :
 * + 3175-5-65 Created File
 * ~ 3176-1-35 Worked it to use libNIMH... cleaned up stuff by quite 
 * bit.
 * - 3176-1-35 BTW... we are now placing common elements into lamia_object
 * + 3176-1-35 and now, we have a lamia object placed into here.
 * TODO :
 * * Finish Writing <more or less done>
 * * Debug
 * Purpose :
 * Create a system that allows us to have multiple interpretors set up.
 */

#include <libNIMH/NIMH.h>

#ifndef __LAMIA_SYSTEM_INTERPRETORS_H__
#define __LAMIA_SYSTEM_INTERPRETORS_H__

typedef nimh_data lamia_interpretors;

typedef struct {
    lamia_object *base;
    void *virtual_machine;
    void *byte_code_info;
} lamia_interpretor_data lamia_interpretor;

lamia_interpretors symbol_table_gen(nimh_book*);
lamia_interpretors add_symbol(nimh_book*,lamia_symbol*);

lamia_interpretor lamia_interpretor(nimh_book*,nimh_string*,lamia_interpretor*=nil);

lamia_vm_type type(nimh_book*,nimh_string*);

void* virtual_machine(nimh_book*,nimh_string*, void*=nil);
lamia_interpretor* byte_code_info(nimh_book,nimh_string*);

void store_state(nimh_book*,nimh_string*=nil);
void restore_state(nimh_book*,nimh_string*=nil);

#endif // __LAMIA_SYSTEM_INTERPRETORS_H__
