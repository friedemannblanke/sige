# Sige -- Static Site Generator
[Helpful](https://github.com/oz123/awesome-c)

## TBD
* Database: SQL, SQLite, plain JSON?

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
* Maybe: Only take HTML, let user handle conversion
* Accept stdin as post
* Handle multiple posts at once, add in order of arguments

## Design
* C compatible YAML parsing library? -> libYAML
* External Markdown to HTML converter
* Templating/ search & replace: regex library

* Struct post
	* date Date
	* str Author
	* str Title
	* str Body
	* str Link

* Struct date
	* int Year
	* int Month
	* int Day

* post getMetaData(str) **CHANGED**
	For now, Sige will not automatically extract metadata, however it may be specified in the form of command line arguments.
	The reason behind this is, that the application will, for now, not handle Markdown conversion itself, and instead rely on the user to provide an HTML file as input.
		At the time of writing this seems like the most sensible option, because it allows the user greater control over the final product, and can easily be replicated by piping to Sige's stdin.
* str mdToHtml(str)
	* make use of library or external application
* int implementTemplates(post)
	* write to file system
	* Signature of individual template implementors depends on type of template

## Evaluation
1. Handles metadata
2. Constructs various HTML files based on templates
3. Builds ready-to-deploy site directories
4. Friendly towards shell scripting with focus on command line options over interactivity
5. Safeguards against accidental content deletion
