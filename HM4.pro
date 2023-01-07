QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=\
    account.cpp \
    accounts_customer.cpp \
    add_emp.cpp \
    bank.cpp \
    date.cpp\
    customer.cpp \
    customer_page.cpp \
    del_emp.cpp \
    delete_customer.cpp \
    emploee.cpp \
    emploee_page.cpp \
    inf_emp_for_manag.cpp \
    information_cust_for_emp.cpp \
    information_customer.cpp \
    leave_hours.cpp \
    list_leave.cpp \
    list_overtime.cpp \
    login.cpp \
    main.cpp \
    manager.cpp \
    manager_page.cpp \
    opening_account.cpp \
    overtime_hour.cpp \
    print_customer_with_ncod.cpp \
    print_emp_with_pcod.cpp \
    set_cond_by_emp.cpp \
    view_bank.cpp

HEADERS += \
    account.h \
    accounts_customer.h \
    add_emp.h \
    bank.h \
    customer.h \
    customer_page.h \
    date.h \
    del_emp.h \
    delete_customer.h \
    emploee.h \
    emploee_page.h \
    inf_emp_for_manag.h \
    information_cust_for_emp.h \
    information_customer.h \
    leave_hours.h \
    list_leave.h \
    list_overtime.h \
    login.h \
    manager.h \
    manager_page.h \
    opening_account.h \
    overtime_hour.h \
    print_customer_with_ncod.h \
    print_emp_with_pcod.h \
    set_cond_by_emp.h \
    view_bank.h

FORMS += \
    accounts_customer.ui \
    add_emp.ui \
    customer_page.ui \
    del_emp.ui \
    delete_customer.ui \
    emploee_page.ui \
    inf_emp_for_manag.ui \
    information_cust_for_emp.ui \
    information_customer.ui \
    leave_hours.ui \
    list_leave.ui \
    list_overtime.ui \
    login.ui \
    manager_page.ui \
    opening_account.ui \
    overtime_hour.ui \
    print_customer_with_ncod.ui \
    print_emp_with_pcod.ui \
    set_cond_by_emp.ui \
    view_bank.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
