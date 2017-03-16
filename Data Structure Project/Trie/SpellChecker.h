#ifndef SPELLCHECKER_H_INCLUDED
#define SPELLCHECKER_H_INCLUDED


void SpellChecker(Trie *trie, char *key)
{
    int length = strlen(key);
    if (length == 0) return;

    if (!haveWord(trie, key)) {
        key[length - 1] = '\0';
        autoComplete(trie, key);
        SpellChecker(trie, key);

    }

}


#endif // SPELLCHECKER_H_INCLUDED
