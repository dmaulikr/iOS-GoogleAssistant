// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/documentation.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_VERSION < 30002
#error This file was generated by a newer version of protoc which is incompatible with your Protocol Buffer library sources.
#endif
#if 30002 < GOOGLE_PROTOBUF_OBJC_MIN_SUPPORTED_VERSION
#error This file was generated by an older version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class GAPIDocumentationRule;
@class GAPIPage;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - GAPIDocumentationRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface GAPIDocumentationRoot : GPBRootObject
@end

#pragma mark - GAPIDocumentation

typedef GPB_ENUM(GAPIDocumentation_FieldNumber) {
  GAPIDocumentation_FieldNumber_Summary = 1,
  GAPIDocumentation_FieldNumber_Overview = 2,
  GAPIDocumentation_FieldNumber_RulesArray = 3,
  GAPIDocumentation_FieldNumber_DocumentationRootURL = 4,
  GAPIDocumentation_FieldNumber_PagesArray = 5,
};

/**
 * `Documentation` provides the information for describing a service.
 *
 * Example:
 * <pre><code>documentation:
 *   summary: >
 *     The Google Calendar API gives access
 *     to most calendar features.
 *   pages:
 *   - name: Overview
 *     content: &#40;== include google/foo/overview.md ==&#41;
 *   - name: Tutorial
 *     content: &#40;== include google/foo/tutorial.md ==&#41;
 *     subpages;
 *     - name: Java
 *       content: &#40;== include google/foo/tutorial_java.md ==&#41;
 *   rules:
 *   - selector: google.calendar.Calendar.Get
 *     description: >
 *       ...
 *   - selector: google.calendar.Calendar.Put
 *     description: >
 *       ...
 * </code></pre>
 * Documentation is provided in markdown syntax. In addition to
 * standard markdown features, definition lists, tables and fenced
 * code blocks are supported. Section headers can be provided and are
 * interpreted relative to the section nesting of the context where
 * a documentation fragment is embedded.
 *
 * Documentation from the IDL is merged with documentation defined
 * via the config at normalization time, where documentation provided
 * by config rules overrides IDL provided.
 *
 * A number of constructs specific to the API platform are supported
 * in documentation text.
 *
 * In order to reference a proto element, the following
 * notation can be used:
 * <pre><code>&#91;fully.qualified.proto.name]&#91;]</code></pre>
 * To override the display text used for the link, this can be used:
 * <pre><code>&#91;display text]&#91;fully.qualified.proto.name]</code></pre>
 * Text can be excluded from doc using the following notation:
 * <pre><code>&#40;-- internal comment --&#41;</code></pre>
 * Comments can be made conditional using a visibility label. The below
 * text will be only rendered if the `BETA` label is available:
 * <pre><code>&#40;--BETA: comment for BETA users --&#41;</code></pre>
 * A few directives are available in documentation. Note that
 * directives must appear on a single line to be properly
 * identified. The `include` directive includes a markdown file from
 * an external source:
 * <pre><code>&#40;== include path/to/file ==&#41;</code></pre>
 * The `resource_for` directive marks a message to be the resource of
 * a collection in REST view. If it is not specified, tools attempt
 * to infer the resource from the operations in a collection:
 * <pre><code>&#40;== resource_for v1.shelves.books ==&#41;</code></pre>
 * The directive `suppress_warning` does not directly affect documentation
 * and is documented together with service config validation.
 **/
@interface GAPIDocumentation : GPBMessage

/**
 * A short summary of what the service does. Can only be provided by
 * plain text.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *summary;

/** The top level pages for the documentation set. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<GAPIPage*> *pagesArray;
/** The number of items in @c pagesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger pagesArray_Count;

/**
 * A list of documentation rules that apply to individual API elements.
 *
 * **NOTE:** All service configuration rules follow "last one wins" order.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<GAPIDocumentationRule*> *rulesArray;
/** The number of items in @c rulesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger rulesArray_Count;

/** The URL to the root of documentation. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *documentationRootURL;

/**
 * Declares a single overview page. For example:
 * <pre><code>documentation:
 *   summary: ...
 *   overview: &#40;== include overview.md ==&#41;
 * </code></pre>
 * This is a shortcut for the following declaration (using pages style):
 * <pre><code>documentation:
 *   summary: ...
 *   pages:
 *   - name: Overview
 *     content: &#40;== include overview.md ==&#41;
 * </code></pre>
 * Note: you cannot specify both `overview` field and `pages` field.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *overview;

@end

#pragma mark - GAPIDocumentationRule

typedef GPB_ENUM(GAPIDocumentationRule_FieldNumber) {
  GAPIDocumentationRule_FieldNumber_Selector = 1,
  GAPIDocumentationRule_FieldNumber_Description_p = 2,
  GAPIDocumentationRule_FieldNumber_DeprecationDescription = 3,
};

/**
 * A documentation rule provides information about individual API elements.
 **/
@interface GAPIDocumentationRule : GPBMessage

/**
 * The selector is a comma-separated list of patterns. Each pattern is a
 * qualified name of the element which may end in "*", indicating a wildcard.
 * Wildcards are only allowed at the end and for a whole component of the
 * qualified name, i.e. "foo.*" is ok, but not "foo.b*" or "foo.*.bar". To
 * specify a default for all applicable elements, the whole pattern "*"
 * is used.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *selector;

/** Description of the selected API(s). */
@property(nonatomic, readwrite, copy, null_resettable) NSString *description_p;

/**
 * Deprecation description of the selected element(s). It can be provided if an
 * element is marked as `deprecated`.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *deprecationDescription;

@end

#pragma mark - GAPIPage

typedef GPB_ENUM(GAPIPage_FieldNumber) {
  GAPIPage_FieldNumber_Name = 1,
  GAPIPage_FieldNumber_Content = 2,
  GAPIPage_FieldNumber_SubpagesArray = 3,
};

/**
 * Represents a documentation page. A page can contain subpages to represent
 * nested documentation set structure.
 **/
@interface GAPIPage : GPBMessage

/**
 * The name of the page. It will be used as an identity of the page to
 * generate URI of the page, text of the link to this page in navigation,
 * etc. The full page name (start from the root page name to this page
 * concatenated with `.`) can be used as reference to the page in your
 * documentation. For example:
 * <pre><code>pages:
 * - name: Tutorial
 *   content: &#40;== include tutorial.md ==&#41;
 *   subpages:
 *   - name: Java
 *     content: &#40;== include tutorial_java.md ==&#41;
 * </code></pre>
 * You can reference `Java` page using Markdown reference link syntax:
 * `[Java][Tutorial.Java]`.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *name;

/**
 * The Markdown content of the page. You can use <code>&#40;== include {path} ==&#41;</code>
 * to include content from a Markdown file.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *content;

/**
 * Subpages of this page. The order of subpages specified here will be
 * honored in the generated docset.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<GAPIPage*> *subpagesArray;
/** The number of items in @c subpagesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger subpagesArray_Count;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)