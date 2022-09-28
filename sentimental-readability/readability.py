# TODO

while True:
    #get input
    text = str(input("Text: "))
    length = len(text)

    #start counters
    letters = 0
    words = 1
    sentences = 0

    #count letters
    for i in range(length):
        if(text[i].isalpha()):
            letters += 1
    #count words
        if (text[i].isspace()):
            words +=1

    #count sentences
        if(text[i] == '.' or text[i] == '?' or text[i] == '!'):
            sentences +=1

    #Coleman-Liau calculation
    calc = round((0.0588 * letters / words *100) - (0.296 * sentences / words *100) - 15.8)

    if calc < 1:
        print ("Before Grade 1")
    elif calc > 16:
        print ("Grade 16+")
    else:
        print ("Grade " + calc)

    break