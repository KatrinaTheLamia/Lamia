/*nimh-doc
 * Project : %(Lamia)project
 * File : %(lamia-source)path/Lamia/egg/config.h
 * Authors : %(KatrinaTheLamia)author
 * Groups : %(NIMHLabs)group
 * License : %(lamia-doc)path/License.txt
 * Created : 3175-1-59
 * Revisions :
 * + 3175-1-59 Created File
 * TODO: 
 * * Documentation
 * * Fill out the file
 * Purpose :
 * Config specific to an Egg. Without going into specifics that should be 
 * able to be seen via DOM.
 */

#ifndef __LAMIA_SYSTEM_EGG_CONFIG_H__
#defein __LAMIA_SYSTEM_EGG_CONFIG_H_

/*nimh-doc
 * Object: lamia_config
 * Field : base : lamia_object : lamia base object.
 * Field : key : nimh_string : the configuration entry name
 * Field : data_type : nimh_type : what type of data is this object
 * Field : data : nimh_data : the payload.
 * Field : next : (void*) lamia_config_entry : the previous entry.
 * Field : prev : (void*) lamia_config_entry : the next entry.
 * Purpose :
 * General purpose config key entry item.
 */
typedef struct {
  lamia_object *base;
  nimh_string *key;
  nimh_type data_type;
  nimh_data *data;
  void *prev, *next;
} lamia_config_entry_data lamia_config_entry;

/*nimh-doc
 * Object: lamia_config
 * Field: base : lamia_object : base object
 * Field: name : nimh_string : configuration name
 * Field: storage_handle : nimh_string : storage handle we will use
 * field: head_node : lamia_config_entry : the top node of this config file.
 * Purpose:
 * The head node of this particular config information.
 */
typedef struct {
  lamia_object *base;
  nimh_string *name, *storage_handle;
  lamia_config_entry *head_node;
} lamia_config lamia_config;

/*nimh-doc
 * Member : load_config
 * Param : nimh_book : the book Lamia is reading from
 * Param : nimh_string : configuration to assign the new config to
 * Param : nimh_string : the storage handle to look at
 * Purpose:
 * Load, or potentially reload a storage method used.
 */
nimh_book* load_config(nimh_book*,nimh_string*,nimh_string*);

/*nimh-doc
 * Member : lamia_config
 * Param : nimh_book : the book Lamia is talking to
 * Param : nimh_string : Lamia config name
 * Param : nimh_string : Lamia key
 * Param : nimh_data : optional : type of data to be assigned
 * Param : nimh_type : optional : data to be assigned to that type.
 * Return : nimh_data : data requested
 * Return : nimh_book : the book Lamia is reading from.
 * Purpose
 * A duel get/set function for the return type of nimh_data.
 * In the case of nimh_book return it is a mixture of touch and set function
 */
nimh_book* lamia_config(nimh_book*,nimh_string*,nimh_string*,nimh_data=nil,nimh_type*=nil);
nimh_data* lamia_config(nimh_book*,nimh_string*,nimh_string*,nimh_data=nil,nimh_type*=nil);

/*nimh-doc
 * Private Member: _traverse_right
 * Private Member: _traverse_left
 * Param : lamia_config_entry : the current config entry
 * Param : nimh_string : the target key
 * Return : lamia_config_entry
 * Functions for traversing the configs
 */
static lamia_config_entry _traverse_right(lamia_config_entry* mine,nimh_string* target) {
  if(equals(mine->key, target)) {
    return mine;
  }
  return _traverse_right(mine->next,target);
}

static lamia_config_entry _traverse_left(lamia_config_entry* mine, nimh_string* target) {
  if(equals(lamia_config_entry->key, target)) {
    return mine;
  }
  return _traverse_left(mine->prev,target);
}

/*nimh-doc
 * Thread Member: lamia_config_search
 * parameter: nimh_book: the book Lamia is looking at
 * parameter: nimh_string: the name of nimh_thread to use
 * parameter: nimh_string: the name of the data that we will be targetting
 * parameter: nimh_string: the name of the data that the answer will be dropped in on completion.
 */
void lamia_config_search(nimh_book*,nimh_string*,nimh_string*,nimh_string*);

#endif /* __LAMIA_SYSTEM_EGG_CONFIG_H__ */
