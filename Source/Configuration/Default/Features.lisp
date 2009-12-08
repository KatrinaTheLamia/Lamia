
(disable loadinto (list (nimh_disabler)))

(storage loadinot (list (
			 sqlite3
			 sqlite2
			 mysql
			 postgresql
			 oracle
			 kirbybase
			 flat
			 )))

(nimhdom3 loadinto (list (
                          nimhdom3-save-restore
			  )))

(dom loadinto (list (
		     nimhdom3
		     ;nimhdom2
		     ;nimhdom1
                    )))

(css loadinto (list (
		     nimhcss3
		     ;nimhcss2
		     ;nimhcss1
		     )))

(ecmascript loadinto (list (
			    VPop
			    Spidermonkey
			    ; nimhecma
			    ; Rhino
			    ; JS
			    ; JS-old
			    )))

(python loadinto (list (
			; python3
			python2
			; python1
			jython23
			jython24
			jython25
			jython27
			jython3
			ironpython
			)))

(perl loadinto (list (
		      perl6
		      perl5
		      ;perl4
		      ;jerl6
		      ;ironperl5
		      ;ironperl6
		      )))

(ruby loadinto (list (
		      ; ruby19
		      ruby18
		      ; jruby
		      )))

(inc_lisp loadinto (list (
			 clisp
			 ; clojure
			 )))

(haskal loadinto (list (
			nil
			)))

(protocols loadinto (list (
			   http11
			   http10
			   http09
			   irc
			   mailto
			   ldap
			   soap
			   miranda
			   git
			   svn
			   cvs
			   bind
			   )))

(markup loadinto (list (
		       html5
		       html4
		       html32
		       html2
		       xhtml2
		       xhtml11
                       atom_feed
		       rss
		       canvas
		       wml
		       ; svg
		       ; smil
		       ; xslt
		       ; xslfo
		       ; hlink
		       )))

(outside-programs loadinto (list (
		            mplayer
			    torrent
			    ; irssi
			    ; lirc
			    )))


(scription loadinto (list (
			   lua
			   python
			   perl
			   ruby
			   inc-lisp
			   haskal
			   intercal
			   greasesnake
			   )))

(scripted-extensions loadinto (list (
				     search-engine
				     find-page
			             youtube
                                     twitter
				     facebook
				     ; phpbb
				     ; ikonboard
				     ; google
				     ; stumbleupon
                                     openid
			             )))


(certsystems loadinot (list ( 
			      curl-compat
			      tls
			      ssl
			      )))

(core loadinto (list (
		      disable
		      dom
		      css
		      protocols
		      markup
		      outside-programs
		      scription
		      scripted-extensions
		      certsystems
		      )))
