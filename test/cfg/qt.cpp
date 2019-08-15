
// Test library configuration for qt.cfg
//
// Usage:
// $ cppcheck --check-library --enable=information --inconclusive --error-exitcode=1 --suppress=missingIncludeSystem --inline-suppr --library=qt test/cfg/qt.cpp
// =>
// No warnings about bad library configuration, unmatched suppressions, etc. exitcode=0
//

#include <QObject>
#include <QString>
#include <QVector>
#include <QtPlugin>
#include <QFile>
#include <cstdio>
#include <QCoreApplication>


void QString1(QString s)
{
    for (int i = 0; i <= s.size(); ++i) {
        // cppcheck-suppress stlOutOfBounds
        s[i] = 'x';
    }
}

int QString2()
{
    QString s;
    // FIXME cppcheck-suppress reademptycontainer
    return s.size();
}

QString::iterator QString3()
{
    QString qstring1;
    QString qstring2;
    // cppcheck-suppress iterators2
    for (QString::iterator it = qstring1.begin(); it != qstring2.end(); ++it)
    {}

    QString::iterator it = qstring1.begin();
    // cppcheck-suppress returnDanglingLifetime
    return it;
}

void QList1(QList<int> intListArg)
{
    for (int i = 0; i <= intListArg.size(); ++i) {
        // cppcheck-suppress stlOutOfBounds
        intListArg[i] = 1;
    }
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    intListArg[intListArg.length()] = 5;
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    intListArg[intListArg.count()] = 10;
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    printf("val: %d\n", intListArg[intListArg.size()]);

    QList<QString> qstringList1{"one", "two"};
    (void)qstringList1[1];

    QList<QString> qstringList2 = {"one", "two"};
    (void)qstringList2[1];
    qstringList2.clear();
    // TODO: cppcheck-suppress containerOutOfBounds #9243
    (void)qstringList2[1];

    QList<QString> qstringList3;
    qstringList3 << "one" << "two";
    // FIXME: The following containerOutOfBounds suppression is wrong #9242
    // Please remove the suppression as soon as this is fixed
    // cppcheck-suppress containerOutOfBounds
    (void)qstringList3[1];
    // cppcheck-suppress ignoredReturnValue
    qstringList3.startsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringList3.endsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringList3.count();
    // cppcheck-suppress ignoredReturnValue
    qstringList3.length();
    // cppcheck-suppress ignoredReturnValue
    qstringList3.size();
    // cppcheck-suppress ignoredReturnValue
    qstringList3.at(5);
    // cppcheck-suppress invalidFunctionArg
    (void)qstringList3.at(-5);

    QList<QString> qstringList4;
    // cppcheck-suppress containerOutOfBounds
    (void)qstringList4[0];
    qstringList4.append("a");
    (void)qstringList4[0];
    qstringList4.clear();
    // TODO: cppcheck-suppress containerOutOfBounds #9243
    (void)qstringList4[0];
}

QList<int>::iterator QList3()
{
    QList<int> qlist1;
    QList<int> qlist2;
    // cppcheck-suppress iterators2
    for (QList<int>::iterator it = qlist1.begin(); it != qlist2.end(); ++it)
    {}

    QList<int>::iterator it = qlist1.begin();
    // TODO: cppcheck-suppress returnDanglingLifetime
    return it;
}

void QStringList1(QStringList stringlistArg)
{
    for (int i = 0; i <= stringlistArg.size(); ++i) {
        // cppcheck-suppress stlOutOfBounds
        stringlistArg[i] = "abc";
    }
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    stringlistArg[stringlistArg.length()] = "ab";
    stringlistArg[stringlistArg.length() - 1] = "ab"; // could be valid
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    stringlistArg[stringlistArg.count()] = "12";
    stringlistArg[stringlistArg.count() - 1] = "12"; // could be valid
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    (void)stringlistArg[stringlistArg.size()];
    (void)stringlistArg[stringlistArg.size() - 1]; // could be valid

    QStringList qstringlist1{"one", "two"};
    (void)qstringlist1[1];

    QStringList qstringlist2 = {"one", "two"};
    (void)qstringlist2[1];

    QStringList qstringlist3;
    qstringlist3 << "one" << "two";
    // FIXME: The following containerOutOfBounds suppression is wrong #9242
    // Please remove the suppression as soon as this is fixed
    // cppcheck-suppress containerOutOfBounds
    (void)qstringlist3[1];
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.startsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.endsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.count();
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.length();
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.size();
    // cppcheck-suppress ignoredReturnValue
    qstringlist3.at(5);
    // cppcheck-suppress invalidFunctionArg
    (void)qstringlist3.at(-5);
}

QStringList::iterator QStringList2()
{
    QStringList qstringlist1;
    QStringList qstringlist2;
    // cppcheck-suppress iterators2
    for (QStringList::iterator it = qstringlist1.begin(); it != qstringlist2.end(); ++it)
    {}

    QStringList::iterator it = qstringlist1.begin();
    // cppcheck-suppress returnDanglingLifetime
    return it;
}

void QVector1(QVector<int> intVectorArg)
{
    for (int i = 0; i <= intVectorArg.size(); ++i) {
        // cppcheck-suppress stlOutOfBounds
        intVectorArg[i] = 1;
    }
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    intVectorArg[intVectorArg.length()] = 5;
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    intVectorArg[intVectorArg.count()] = 10;
    // cppcheck-suppress containerOutOfBoundsIndexExpression
    printf("val: %d\n", intVectorArg[intVectorArg.size()]);

    QVector<QString> qstringVector1{"one", "two"};
    (void)qstringVector1[1];

    QVector<QString> qstringVector2 = {"one", "two"};
    (void)qstringVector2[1];

    QVector<QString> qstringVector3;
    qstringVector3 << "one" << "two";
    // FIXME: The following containerOutOfBounds suppression is wrong #9242
    // Please remove the suppression as soon as this is fixed
    // cppcheck-suppress containerOutOfBounds
    (void)qstringVector3[1];
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.startsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.endsWith("one");
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.count();
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.length();
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.size();
    // cppcheck-suppress ignoredReturnValue
    qstringVector3.at(5);
    // cppcheck-suppress invalidFunctionArg
    (void)qstringVector3.at(-5);
}

QVector<int>::iterator QVector2()
{
    QVector<int> qvector1;
    QVector<int> qvector2;
    // cppcheck-suppress iterators2
    for (QVector<int>::iterator it = qvector1.begin(); it != qvector2.end(); ++it)
    {}

    QVector<int>::iterator it = qvector1.begin();
    // TODO cppcheck-suppress returnDanglingLifetime
    return it;
}

// Verify that Qt macros do not result in syntax errors, false positives or other issues.
class MacroTest1: public QObject {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.foo.bar" FILE "test.json")

public:
    explicit MacroTest1(QObject *parent = 0);
    ~MacroTest1();
};

class MacroTest2 {
    Q_DECLARE_TR_FUNCTIONS(MacroTest2)

public:
    MacroTest2();
    ~MacroTest2();
};

void MacroTest2_test()
{
    // TODO: remove suppression when #9002 is fixed
    // cppcheck-suppress checkLibraryFunction
    QString str = MacroTest2::tr("hello");
    QByteArray ba = str.toLatin1();
    printf(ba.data());

#ifndef QT_NO_DEPRECATED
    // TODO: remove suppression when #9002 is fixed
    // cppcheck-suppress checkLibraryFunction
    str = MacroTest2::trUtf8("test2");
    ba = str.toLatin1();
    printf(ba.data());
#endif
}

void validCode(int * pIntPtr)
{
    if (QFile::exists("test")) {
    }

    if (pIntPtr != Q_NULLPTR) {
        *pIntPtr = 5;
    }

    if (pIntPtr && *pIntPtr == 1) {
        forever {
        }
    } else if (pIntPtr && *pIntPtr == 2) {
        Q_FOREVER {
        }
    }

    if (Q_LIKELY(pIntPtr)) {}
    if (Q_UNLIKELY(!pIntPtr)) {}

    printf(QT_TR_NOOP("Hi"));
}

void ignoredReturnValue()
{
    // cppcheck-suppress ignoredReturnValue
    QFile::exists("test");
    QFile file1("test");
    // cppcheck-suppress ignoredReturnValue
    file1.exists();
}

void nullPointer(int * pIntPtr)
{
    int * pNullPtr = Q_NULLPTR;
    // cppcheck-suppress nullPointer
    *pNullPtr = 1;

    if (pIntPtr != Q_NULLPTR) {
        *pIntPtr = 2;
    } else {
        // cppcheck-suppress nullPointerRedundantCheck
        *pIntPtr = 3;
    }
}
