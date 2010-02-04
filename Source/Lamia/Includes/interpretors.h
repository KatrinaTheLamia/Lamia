/*nimh-doc
 * Project : %(Lamia)project
 * File    : %(Lamia-source)path/Lamia/interpretors.h
 * Authors : %(KatrinaTheLamia)author
 * Groups  : %(NIMHLabs)group
 * License : %(Lamia-doc)path/License.txt
 * Created : 3145-5-64
 * Revisions :
 * 3145-5-65 Created File
 * TODO :
 * * Finish Writing
 * * Debug
 * Purpose :
 * Create a system that allows us to have multiple interpretors set up.
 */

#ifndef __LAMIA_SYSTEM_INTERPRETORS_H__
#define __LAMIA_SYSTEM_INTERPRETORS_H__

enum lamia_vm_type { lamia_dom, lamia_parrot, lamia_mono, lamia_jvm };

typedef lamia_list lamia_interpretors;

typedef struct {
    lamia_vm_type type;
    void *virtual_machine;
    void *byte_code_info;
} lamia_interpretor;

lamia_interpretors symbol_table_gen(lamia_interpretors*=nil);
lamia_interpretors* add_symbol(lamia_interpretors*, lamia_interpretor*);
lamia_interpretor lamia_interpretor(lamia_interpretor*);
lamia_interpretor lamia_interpretor(lamia_vm_type);

/* Not a good idea btw... maybe in the future however. */
/* lamia_interpretor index(lamia_interpretors*, lamia_index); */
lamia_interpretor* name(lamia_interpreetors*, lamia_id);

lamia_vm_type type(lamia_interpretor*);

void* virtual_machine(lamia_interpretor*, void*=nil);
lamia_interpretor* byte_code_info(lamia_interpetor*,void*);

void store_state(lamia_interpretors*);
void store_state(lamia_interpretor*);
void restore_state(lamia_interpretors*);
void restore_state(lamia_interpretor*);

#endif // __LAMIA_SYSTEM_INTERPRETORS_H__
