# Sample Markdown Document
In your homework assignments, you will have non-coding portions that will require you to type your answers in a plain-text file. The GitHub WebUI automatically renders specific file types into HTML making them more readable. [Markdown](http://daringfireball.net/projects/markdown/) is a markup language that is supported by GitHub and it makes writing formatted texted files a lot easier.

This document will show you how to write a text file using Markdown.

----

## Markdown
Markdown is a human-readable structured plain text format that is used to convert text into HTML. GitHub automatically renders Markdown into HTML.

This is a crash course on how to use Markdown. The following section will show you the plain text used to generate the document shown in the rendering section.

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

You can refer to an image or file in your repository using relative paths such as:

![Git File Lifecycle](git-file-lifecycle.png "Git File Lifecycle")
>figure courtesy of the [Pro Git](http://git-scm.com/book) book by Scott Chacon
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

![Git File Lifecycle](git-file-lifecycle.png "Git File Lifecycle")
>figure courtesy of the [Pro Git](http://git-scm.com/book) book by Scott Chacon
Markdown is easy
Markdown is too easy
Fancy git move
