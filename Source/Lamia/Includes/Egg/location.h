/*nimh-doc
 * Project : %(Lamia)project
 * File : %(Lamia-source)path/Lamia/egg/location.h
 * Authors : %(KatrinaTheLamia)/author
 * Groups : %(NIMHLabs)group
 * License : %(Lamia-doc)path/License.txt
 * Created : 3175-1-44
 * Revisions :
 * + 3175-1-44
 * TODO :
 * * Finish Writing
 * * Document ERIS DAMNIT!
 * * Debug
 * Purpose :
 * A data type meant to deconstruct a web based location. Since one of the 
 * main goals of Lamia is to be able to extend well beyond HTML, into the 
 * areas of email, twitter, facebook, IM, IRC, Gopher, Archie, etc., 
 * etc.--locations are going to get very odd. Since going after a more 
 * modular system may make more sense here, this is what we will be opting 
 * to do here.
 */

#include <libNIMH/NIMH.h>

#ifndef __LAMIA_SYSTEM_LOCATION_H__
#define __LAMIA_SYSTEM_LOCATION_H__

#include <egg/location.h>

/*nimh-doc
 * Type : lamia_location
 * Member : base : lamia_object : parent object
 * Member : protocol : lamia_protocol : the protocol apparently used.
 * Member : domain : lamia_domain : the domain this site targets
 * Member : service : lamia_service : is this http, gopher, irc, or what?
 * Member : login : lamia_remote_user : login information for this location
 * Member : target : lamia_target : what file are we grabbing.
 * Description :
 * Generally used to store information for locations. Be it locations that 
 * an item links to, or the location of an item we are talking about.
 */

typedef struct { 
    lamia_object *base;
    lamia_protocol *protocol;
  /*
   * Lamia protocol type use here, to allow easy switching in and out 
   * data information for handling the protocol.
   */
    lamia_domain *domain;
  /*
   * Domain type created to story domains in the standard BIND/named systems 
   * Popular today, as well as IPv4, IPv6, Catnip, NetBIOS, TPX/SPX, SIP and 
   * other systems to be substituded into the code.
   */
    lamia_service *service;
  /*
   * Would normally be a port value, however, since we are wanting to stick to
   * other less standard addressing systems, having this as a long/long may 
   * not be good for expanding upon later.
   */
    lamia_remote_user *login;
  /*
   * On the login, I will note for later:
   * this system is mean to allow Lamia to remember twitter, facebook, google,
   * openid, yahoo and other forms of login information for sites. It also 
   * will try to remember and figure out session based cookies for logins of 
   * that nature, and just be setup to forget and remember accounts. Check your 
   * configuration for more information.
   * this was originally going to be based on the user:password@site system--but 
   * I figured, why not over engineer it?
   */
     lamia_target *target;
  /*
   * Typical URL systems would have this as a path. However, since our goal with
   * the domain system kind of screws us up here (with goals of wanting to allow 
   * for targetting email complete domains in our queries), a general "target" type 
   * may be more applicable here.
   */
} lamia_location_data lamia_location;

/*nimh-doc
 * Member : protocol
 * Param : nimh_book : the %(nimh_book)type that this protocol information is stored in.
 * Param : nimh_string : the location of this protocol information.
 * Param : lamia_protocol : optional : %(nil)value : substitute new protocol entry?
 * Return : lamia_protocol : the %(lamia_protocol)type we requested.
 * Purpose :
 * Simple get/set function.
 */
lamia_protocol protocol(nimh_book*,nimh_string*,lamia_protocol*=nil);

/*nimh-doc
 * Member : domain
 * Param : nimh_book : the %(nimh_book)type that this lamia is reading from.
 * Param : nimh_string : since we may want to cache or garbage various 
 *                       domains, this points to where the domain is kept
 * Param : lamia_domain : optional : %(nil)value : sub in new domain?
 * Return : lamia_domain : the domain information associated with this object.
 * Purpose :
 * simple get/set functionality
 */
lamia_domain domain(nimh_book*,nimh_string*,lamia_domain*=nil);

/*nimh-doc
 * Member : service
 * Param : nimh_book: the %(nimh_book)type this lamia is reading from.
 * Param : nimh_string : the name the service information for this is stored
 * Param : lamia_service : optional : %(nil)value : sub in new service?
 * Return : lamia_service : requested service
 * Purpose :
 * simple get/set funcationality
 */
lamia_service service(nimh_book*,nimh_string*,lamia_service*=nil);

/*nimh-doc
 * Member: remote_user
 * Param : nimh_book : the %(nimh_book)type this lamia is looking at.
 * Param : nimh_string : the name where the %(remote_user)type is stored
 * Param : lamia_remote_user : optional : %(nil)value : sub in new remote_user?
 * Return : lamia_remote_user : requested user information
 * Purpose : 
 * simple get/set functionality
 */
lamia_remote_user remote_user(nimh_book*,nimh_string*,lamia_remote_user*=nil);

/*nimh-doc
 * Method : target
 * Param : nimh_book : the %(nimh_book)type this lamia is looking at.
 * Param : nimh_string : value we can call this stored value by.
 * Param : lamia_target : optional : nil : sub this target?
 * Return : requested target
 * Purpose :
 * get/set function
 */
lamia_target target(nimh_book*,nimh_string*,lamia_target*=nil);

#endif
