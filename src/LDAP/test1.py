#!/usr/bin/env python
import getpass
import sys

"""
Test connection on ORNL LDAP
Only works on the intranet

"""


FERMI_HOST = 'fermi.ornl.gov'
FERMI_BASE_URL = '/MantidRemote/'


print "Username?"
user = sys.stdin.readline()
username = username%user
pwd = getpass.getpass()


try:
    print "Contacting LDAP...."
    ldap.set_option(ldap.OPT_X_TLS_REQUIRE_CERT, ldap.OPT_X_TLS_NEVER)
    
    ldapmodule_trace_level = 2
    ldapmodule_trace_file = sys.stderr
    
    l = ldap.initialize(url,
                        trace_level=ldapmodule_trace_level,
                        trace_file=ldapmodule_trace_file)
    
    l.simple_bind_s(username,pwd)
    l.unbind() 
    print "*"*30, "\nIf I get here then it worked!\n","*"*30
except ldap.LDAPError, e:
    print e
