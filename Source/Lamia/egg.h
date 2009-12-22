/*nimhdoc
 * Project : %(Lamia)project
 * File    : %(lamia-source)path/Lamia/egg.h
 * Authors : %(KatrinaTheLamia)author
 * Groups  : %(NIMHLabs)group
 * License : %(lamia-doc)path/License.txt
 * Created : 2009-12-07
 * Revisions :
 * 2009-12-07 Created File
 * 3145-5-65 Render changed to reflect frame buffer and curses states
 * 3145-5-65 DOM is put in each egg
 * 3145-5-65 Added get/set state to functions.
 * TODO :
 * * nil
 * Purpose :
 * Create a memory object for managing, switching, killing, restoring, 
 * etc.,
 */

#ifndef __LAMIA_SYSTEM_EGG_H__
#define __LAMIA_SYSTEM_EGG_H__

typedef struct {
    lamia_id name;
    lamia_url location;
    lamia_protocol protocol;
    lamia_render g_render;
    lamia_render c_render;
    lamia_state variables;
    lamia_dom data;
    lamia_config config_differences;
} lamia_egg;

lamia_egg create_lamia(void);
lamia_egg *name(*lamia_egg, lamia_id=nil);
lamia_egg *url(*lamia_egg, lamia_url=nil);
lamia_egg *protocol(*lamia_egg, lamia_protocol=nil);
lamia_egg *variables(*lamia_egg);
lamia_egg *dom(*lamia_egg, dom=nil);
lamia_egg *config(*lamia_egg);

lamia_egg *render(lamia_render_flag);

void store_state(lamia_egg*);
void restore_state(lamia_egg*);

#endif // __LAMIA_SYSTEM_EGG_H__
