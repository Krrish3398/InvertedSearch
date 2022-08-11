# InvertedSearch

# Introduction: 
An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at the cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.

# Requirement Specification :
Implementing this search program mainly consists two important functions.
Indexing
Querying

# Indexing : 
By Indexing, we are creating a database file which contains the index of all words. So this can be termed as Database Creation also. All the files whose index are to be created are selected and inputed to this function. All the files are parsed and words are separated and indexed. They are arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words and the related file details. The index thus created is then stored in the file as database. This file is later used in Querying. While the files are removed or added this index file is updated.

![alt text](https://github.com/Krrish3398/InvertedSearch/blob/main/img/img1.png)

![alt text](https://github.com/Krrish3398/InvertedSearch/blob/main/img/img2.png)

# Searching:
Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed which is parsed into words and those words are searched in the index file. To avoid the overhead of reading the file again, the file is converted back to a linkedList or hashing program, in which the words are searched. The information about the files which contain the words are collected. The ones with more matches are filtered and produced as the result.

![alt text](https://github.com/Krrish3398/InvertedSearch/blob/main/img/img3.png)

![alt text](https://github.com/Krrish3398/InvertedSearch/blob/main/img/img4.png)

# Execution:

```
Execution:.\out.exe file_1.txt file_2.txt
SUCCESS :: Inserting the file name file_1.txt into the file linked list
SUCCESS :: Inserting the file name file_2.txt into the file linked list
1. Create Database
2. Display Database
3. Update Database
4. Search Database
5. Save Database
**Enter Your Option**
1
SUCCESS :: Creation of database for file_1.txt
SUCCESS :: Creation of database for file_2.txt
Do you wish to Continue (y/n): y
2
[index]  [word]  file_count  file/s: File  file_name  word_count
[0]      [ARE]         1       file/s: File  file_2.txt  1
[7]      [Hi]          2       file/s: File  file_1.txt  3  file_2.txt  1
[7]      [HELLO]       1       file/s: File  file_1.txt  1
[7]      [HOW]         1       file/s: File  file_2.txt  1
[7]      [HI]          1       file/s: File  file_2.txt  1
[24]      [YOU]        1       file/s: File  file_2.txt  1
Do you wish to Continue (y/n): y
3
Enter the file name
file_3.txt
SUCCESS :: Inserting the file name file_3.txt into the file linked list
SUCCESS :: Creation of database for file_3.txt
Do you wish to Continue (y/n): y
2
[index]  [word]  file_count  file/s: File  file_name  word_count
[0]      [ARE]        1       file/s: File  file_2.txt  1
[7]      [Hi]         2       file/s: File  file_1.txt  3   file_2.txt  1
[7]      [HELLO]      1       file/s: File  file_1.txt  1
[7]      [HOW]        1       file/s: File  file_2.txt  1
[7]      [HI]         1       file/s: File  file_2.txt  1
[8]      [Im]         1       file/s: File  file_3.txt  1
[10]      [Krishna]   1       file/s: File  file_3.txt  1
[24]      [YOU]       1       file/s: File  file_2.txt  1
Do you wish to Continue (y/n): y
4
Enter the word to search
Im
Word Im is present in 1 file
In file : file_3.txt 1 times
Do you wish to Continue (y/n): y
5
Enter the filename
save.txt
SUCCESS :: Database is saved
Do you wish to Continue (y/n): n

```

# References
1. https://en.wikipedia.org/wiki/Inverted_index
2. https://nlp.stanford.edu/IR-book/html/htmledition/a-first-take-at-building-an-inverted-index-1.html
3. https://www.ijcsi.org/papers/IJCSI-8-4-1-384-392.pdf
4. https://www.elastic.co/guide/en/elasticsearch/guide/current/inverted-index.html
5. https://www.quora.com/Information-Retrieval-What-is-inverted-index
