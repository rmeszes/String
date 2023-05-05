#ifndef STRING_H
#define STRING_H
#include <iostream>

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 *
 * Korábban a len adattag unsigned int típusú volt. Most helyette a size_t típust használjuk.
 * Ezzel a típussal tér vissza a sizeof operator is, később több helyen ezt használjuk
 * mérettípusként.

 */
class String {
    char *pData;        ///< pointer az adatra
    size_t len;         ///< hossz lezáró nulla nélkül
public:
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }
    /// Paraméter nélküli konstruktor:
    String();

    /// Sztring hosszát adja vissza.
    /// @return sztring tényleges hossza (lezáró nulla nélkül).
    size_t size() const;

    /// C-sztringet ad vissza
    /// @return pointer a tárolt, vagy azzal azonos tartalmú nullával lezárt sztring-re.
    const char* c_str() const;

    ~String();

    String(const char);

    String(const char*);

    String(const String&);

    String& operator=(const String);

    char& operator[](size_t idx) const;

}; /// Itt az osztály deklarációjának vége

/// Ide kerülnek a globális operátorok deklarációi.
/// ...
String operator+(const String&, const String&);
String operator+(const String&, const char);
String operator+(const char, String&);

std::ostream& operator<<(std::ostream&, const String&);

std::istream& operator>>(std::istream&, String&);

#endif
