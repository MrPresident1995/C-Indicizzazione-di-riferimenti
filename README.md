Un file contiene un testo composto da un numero indefinito di righe, di lunghezza massima 80 caratteri ognuna.
All'interno del testo appaiono delle sequenze speciali, comprese tra due caratteri dollaro $, a rappresentare dei riferimenti che si possono ripetere più volte nel testo.
Si sappia che il numero massimo di riferimenti possibili è 20.
Si scriva una programma che analizzi il testo proposto, individuando tali sequenze, e assegnando ad ognuna di esse un indice progressivo. Nel far ciò, il programma deve riscrivere il testo su un secondo file sostituendo al riferimento incontrato l'indice ad esso assegnato racchiuso tra quadre, ossia nella forma [<indice>]. Si produca infine un terzo file contenente l'elenco di riferimenti affiancati dal rispettivo indice.

    Nota: i riferimenti possono essere composti da più parole, ma non sono mai spezzati su più righe.
    
--Esempio--
si abbia il seguente file:
    $lorem$ $ipsum$ dolor $sit amet$, consectetur adipiscing elit. Sed viverra
    porttitor diam id posuere. Pellentesque rhoncus vitae ex at consequat. Morbi
    iaculis ut odio $sit amet$ venenatis. Donec quis lectus in diam pharetra
    imperdiet et id $lorem$. In vel congue lectus. Maecenas aliquam quam quis
    turpis consectetur accumsan. Ut id mauris lacinia, interdum mauris eu, mattis
    odio. Nulla tempus in ligula $sit amet$ tincidunt. Donec dignissim neque
    tempus, dapibus $tortor$ nec, sodales nisl. Suspendisse vel $tortor$ vitae lacus
    tristique aliquam in volutpat lectus. Nullam at ultricies diam, nec elementum
    erat. Cras egestas, quam a tincidunt dapibus, $ipsum$ tellus placerat $ipsum$,
    et gravida tellus ligula quis ante.

Il programma deve generare un nuovo file che rispetti il formato del precedente, come:
[1] [2] dolor [3], consectetur adipiscing elit. Sed viverra
porttitor diam id posuere. Pellentesque rhoncus vitae ex at consequat. Morbi
iaculis ut odio [3] venenatis. Donec quis lectus in diam pharetra
imperdiet et id [1]. In vel congue lectus. Maecenas aliquam quam quis
turpis consectetur accumsan. Ut id mauris lacinia, interdum mauris eu, mattis
odio. Nulla tempus in ligula [3] tincidunt. Donec dignissim neque
tempus, dapibus [4] nec, sodales nisl. Suspendisse vel [4] vitae lacus
tristique aliquam in volutpat lectus. Nullam at ultricies diam, nec elementum
erat. Cras egestas, quam a tincidunt dapibus, [2] tellus placerat [2],
et gravida tellus ligula quis ante.

Inoltre occorre generare l'indice dei riferimenti su un terzo file:
    [1] lorem
    [2] ipsum
    [3] sit amet
    [4] tortor
