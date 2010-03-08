/*nimhdoc
 * Project : %(Lamia)project
 * File    : %(lamia-source)path/Lamia/egg.h
 * Authors : %(KatrinaTheLamia)author
 * Groups  : %(NIMHLabs)group
 * License : %(lamia-doc)path/License.txt
 * Created : 2009-12-07
 * Revisions :
 * + 2009-12-07 Created File
 * ~ 3175-5-65 Render changed to reflect frame buffer and curses states
 * ~ 3175-5-65 DOM is put in each egg
 * ~ 3175-5-65 Added get/set state to functions.
 * ~ 3176-1-35 added libNIMH into here
 * - 3176-1-35 removed stuff in lamia_object
 * + 3176-1-35 added lamia_object base
 * TODO :
 * * Documentation... lots and lots of Documention... Eris dammit!
 * Purpose :
 * Create a memory object for managing, switching, killing, restoring, 
 * etc.,
 */

#ifndef __LAMIA_SYSTEM_EGG_H__
#define __LAMIA_SYSTEM_EGG_H__

typedef nimh_data lamia_nest;

typedef struct {
    lamia_object *base;
    lamia_url location;
    lamia_protocol protocol;
    lamia_render *g_render;
    lamia_render *c_render;
    lamia_state variables;
    lamia_dom *data;
    lamia_config config_differences;
} lamia_egg_data lamia_egg;

lamia_egg create_lamia(nimh_book*,nimh_string*);
lamia_egg *name(nimh_book*,nimh_string*, lamia_id);
lamia_egg *url(nimh_book*,nimh_string*, lamia_url);
lamia_egg *protocol(nimh_book*,nimh_string*, lamia_protocol);
lamia_egg *dom(nimh_book*,nimh_string*, lamia_dom);

lamia_id *name(nimh_book*, nimh_string*, lamia_id=nil);
lamia_url *url(nimh_book*, nimh_string*, lamia_url=nil);
lamia_url *protocol(nimh_book*, nimh_string*, lamia_protocol);
lamia_render *render(nimh_book*, nimh_string*, lamia_render_flag);
lamia_state *variables(nimh_book*, nimh_string*);
lamia_dom *dom(nimh_book*,nimh_string*,dom*)
lamia_config *config(nimh_book*, nimh_string*);

lamia_egg *render(nimh_book*, nimh_string*,lamia_render_flag);
lamia_egg *destroy(nimh_book*, nimh_string*,lamia_render_flag);

void store_state(nimh_book*, nimh_string*);
void restore_state(nimh_book*, nimh_string*);

#endif // __LAMIA_SYSTEM_EGG_H__
