### Problem to Solve
According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

In a file called readability.c in a folder called readability, you’ll implement a program that calculates the approximate grade level needed to comprehend some text. Your program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output “Grade 16+” instead of giving the exact index number. If the grade level is less than 1, your program should output “Before Grade 1”.

### Background
So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

> index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

### Specification
For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:

*will contain at least one word;
*will not start or end with a space; and
*will not have multiple spaces in a row.

### How to Test
Try running your program on the following texts, to ensure you see the specified grade level. Be sure to copy only the text, no extra spaces.

>One fish. Two fish. Red fish. Blue fish. (Before Grade 1)
>Would you like them here or there? I would not like them here or there. I would not like them anywhere. (Grade 2)
>Congratulations! Today is your day. You're off to Great Places! You're off and away! (Grade 3)
>Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he 
>
>really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard. (Grade 5)
>In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since. (Grade 7)
>
>Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book 
>
>her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or 
>
>conversation?" (Grade 8)
>When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play 
>
>football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, 
>
>the back of his hand was at right angles to his body, his thumb parallel to his thigh. (Grade 8)
>There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy. (Grade 9)
>It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the 
>
>vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering 
>
>along with him. (Grade 10)
>A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families 
>
>of finite sets, boolean formulas and elements of other countable domains. (Grade 16+)