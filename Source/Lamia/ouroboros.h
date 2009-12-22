/*nimh-doc
 * Project : %(Lamia)project
 * File    : %(Lamia-source)path/Lamia/egg.h
 * Authors : %(KatrinaTheLamia)author
 * Groups  : %(NIMHLabs)group
 * License : %(Lamia-doc)path/License.txt
 * Created : 3145-5-64
 * Revisions :
 * 3145-5-64 Created the file
 * TODO :
 * * Still needs implimentation
 * * Then thorough testing
 * Purpose :
 * Ouroboros is a Lamia system designed to have everything in Lamia 
 * be a form of DOM type setup.
 */

#ifndef __LAMIA_SYSTEM_OUROBOROS_H__
#define __LAMIA_STSTEM_OUROBOROS_H__

typedef struct {
	lamia_sys_pid pid;
	lamia_config configuration;
	lamia_interpretors interpretors;
	lamia_list eggs;
} lamia_ouroboros;

lamia_ouroboros pid(lamia_ouroboros*);
lamia_ouroboros configuration(lamia_ouroboros*, lamia_config*=nil);
lamia_ouroboros interpretors(lamia_ouroboros*, lamia_interpretors*=nil);
lamia_ouroboros eggs(lamia_ouroboros*, index);

lamia_ouroboros render();

void store_state(lamia_ouroboros*);
void restore_state(lamia_ouroboros*);

#endif // __LAMIA_SYSTEM_OUROBOROS_H__
