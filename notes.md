# Sige -- Static Site Generator
[Helpful](https://github.com/oz123/awesome-c)

## Specs
### Templating
* Get metadata (author name, date...) from input file (YAML preamble?)
* Take some content body (HTML/ Markdown), and wrap it in the appropriate boilerplate for a standalone page
* Add reference to post in archive listings
* Add (beginning of?) post on top of home/ feed page in the appropriate section
* Update RSS feed
* Assemble in site directories

### User Interaction/ Configuration
* Maybe: maintain DB of visible posts, allow to remove
	* Would enable automatic link generation
*Only take HTML, let user handle conversion
* Accept stdin as post
* Handle multiple posts at once, add in order of arguments
	//deprioritize since relatively trivial with Bash

## Design
* C compatible YAML parsing library? -> libYAML
* External Markdown to HTML converter
* Templating/ search & replace: regex library

* Struct post
	* date Date
	* str Author
	* str Title
	* str body //TODO
	* str Link

* Struct date
	* int Year
	* int Month
	* int Day

* int implementTemplates(post)
	* write to file system
	* Signature of individual template implementors depends on type of template

## Evaluation
1. Handles metadata
2. Constructs various HTML files based on templates
3. Builds ready-to-deploy site directories
4. Friendly towards shell scripting with focus on command line options over interactivity
5. Safeguards against accidental content deletion

## Implementation: TODO
[ ] fix project structure across multiple files

[ ] Change `struct post` to store `body` in string, instead of as FILE
	* Do not allow file path to be passed as argument
	* Adds needless complication
	* Can easily be replicated by user

[ ] `void getPost(struct post *newPost)`
	Use proven buffered approach

[ ] Output
	implement one template (standalone page), but write for expansion
	[ ] to stdout
	[ ] to file

[ ] `void applyTemplates(struct post *newPost)`
	Replace substrings in template
		Potential custom implementation:
			* Find `pattern` in template
			* `strcat` to combine everything before `pattern` with `textToInsert`
			* `strcat` to combine result of previous step with everything after `pattern`

[ ] `generateURL`
	* Replace ` ` with `-`
	* Lowercase everything
