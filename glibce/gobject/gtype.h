/* GObject - GLib Type, Object, Parameter and Signal Library
 * Copyright (C) 1998-1999, 2000-2001 Tim Janik and Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#if !defined (__GLIB_GOBJECT_H_INSIDE__) && !defined (GOBJECT_COMPILATION)
#error "Only <glib-object.h> can be included directly."
#endif

#ifndef __G_TYPE_H__
#define __G_TYPE_H__

#include        <glib.h>

G_BEGIN_DECLS

/* Basic Type Macros
 */
/**
 * G_TYPE_FUNDAMENTAL:
 * @type: A #GType value.
 * 
 * The fundamental type which is the ancestor of @type.
 * Fundamental types are types that serve as ultimate bases for the derived types, 
 * thus they are the roots of distinct inheritance hierarchies.
 */
#define G_TYPE_FUNDAMENTAL(type)	(g_type_fundamental (type))
/**
 * G_TYPE_FUNDAMENTAL_MAX:
 * 
 * An integer constant that represents the number of identifiers reserved
 * for types that are assigned at compile-time.
 */
#define	G_TYPE_FUNDAMENTAL_MAX		(255 << G_TYPE_FUNDAMENTAL_SHIFT)

/* Constant fundamental types,
 * introduced by g_type_init().
 */
/**
 * G_TYPE_INVALID:
 * 
 * An invalid #GType used as error return value in some functions which return
 * a #GType. 
 */
#define G_TYPE_INVALID			G_TYPE_MAKE_FUNDAMENTAL (0)
/**
 * G_TYPE_NONE:
 * 
 * A fundamental type which is used as a replacement for the C
 * <literal>void</literal> return type.
 */
#define G_TYPE_NONE			G_TYPE_MAKE_FUNDAMENTAL (1)
/**
 * G_TYPE_INTERFACE:
 * 
 * The fundamental type from which all interfaces are derived.
 */
#define G_TYPE_INTERFACE		G_TYPE_MAKE_FUNDAMENTAL (2)
/**
 * G_TYPE_CHAR:
 * 
 * The fundamental type corresponding to #gchar.
 * The type designated by G_TYPE_CHAR is unconditionally an 8-bit signed integer.
 * This may or may not be the same type a the C type "gchar".
 */
#define G_TYPE_CHAR			G_TYPE_MAKE_FUNDAMENTAL (3)
/**
 * G_TYPE_UCHAR:
 * 
 * The fundamental type corresponding to #guchar.
 */
#define G_TYPE_UCHAR			G_TYPE_MAKE_FUNDAMENTAL (4)
/**
 * G_TYPE_BOOLEAN:
 * 
 * The fundamental type corresponding to #gboolean.
 */
#define G_TYPE_BOOLEAN			G_TYPE_MAKE_FUNDAMENTAL (5)
/**
 * G_TYPE_INT:
 * 
 * The fundamental type corresponding to #gint.
 */
#define G_TYPE_INT			G_TYPE_MAKE_FUNDAMENTAL (6)
/**
 * G_TYPE_UINT:
 * 
 * The fundamental type corresponding to #guint.
 */
#define G_TYPE_UINT			G_TYPE_MAKE_FUNDAMENTAL (7)
/**
 * G_TYPE_LONG:
 * 
 * The fundamental type corresponding to #glong.
 */
#define G_TYPE_LONG			G_TYPE_MAKE_FUNDAMENTAL (8)
/**
 * G_TYPE_ULONG:
 * 
 * The fundamental type corresponding to #gulong.
 */
#define G_TYPE_ULONG			G_TYPE_MAKE_FUNDAMENTAL (9)
/**
 * G_TYPE_INT64:
 * 
 * The fundamental type corresponding to #gint64.
 */
#define G_TYPE_INT64			G_TYPE_MAKE_FUNDAMENTAL (10)
/**
 * G_TYPE_UINT64:
 * 
 * The fundamental type corresponding to #guint64.
 */
#define G_TYPE_UINT64			G_TYPE_MAKE_FUNDAMENTAL (11)
/**
 * G_TYPE_ENUM:
 * 
 * The fundamental type from which all enumeration types are derived.
 */
#define G_TYPE_ENUM			G_TYPE_MAKE_FUNDAMENTAL (12)
/**
 * G_TYPE_FLAGS:
 * 
 * The fundamental type from which all flags types are derived.
 */
#define G_TYPE_FLAGS			G_TYPE_MAKE_FUNDAMENTAL (13)
/**
 * G_TYPE_FLOAT:
 * 
 * The fundamental type corresponding to #gfloat.
 */
#define G_TYPE_FLOAT			G_TYPE_MAKE_FUNDAMENTAL (14)
/**
 * G_TYPE_DOUBLE:
 * 
 * The fundamental type corresponding to #gdouble.
 */
#define G_TYPE_DOUBLE			G_TYPE_MAKE_FUNDAMENTAL (15)
/**
 * G_TYPE_STRING:
 * 
 * The fundamental type corresponding to nul-terminated C strings.
 */
#define G_TYPE_STRING			G_TYPE_MAKE_FUNDAMENTAL (16)
/**
 * G_TYPE_POINTER:
 * 
 * The fundamental type corresponding to #gpointer.
 */
#define G_TYPE_POINTER			G_TYPE_MAKE_FUNDAMENTAL (17)
/**
 * G_TYPE_BOXED:
 * 
 * The fundamental type from which all boxed types are derived.
 */
#define G_TYPE_BOXED			G_TYPE_MAKE_FUNDAMENTAL (18)
/**
 * G_TYPE_PARAM:
 * 
 * The fundamental type from which all #GParamSpec types are derived.
 */
#define G_TYPE_PARAM			G_TYPE_MAKE_FUNDAMENTAL (19)
/**
 * G_TYPE_OBJECT:
 * 
 * The fundamental type for #GObject.
 */
#define G_TYPE_OBJECT			G_TYPE_MAKE_FUNDAMENTAL (20)


/* Reserved fundamental type numbers to create new fundamental
 * type IDs with G_TYPE_MAKE_FUNDAMENTAL().
 * Send email to gtk-devel-list@gnome.org for reservations.
 */
/**
 * G_TYPE_FUNDAMENTAL_SHIFT:
 *
 * Shift value used in converting numbers to type IDs.
 */
#define	G_TYPE_FUNDAMENTAL_SHIFT	(2)
/**
 * G_TYPE_MAKE_FUNDAMENTAL:
 * @x: the fundamental type number.
 * 
 * Get the type ID for the fundamental type number @x.
 * Use g_type_fundamental_next() instead of this macro to create new fundamental 
 * types.
 *
 * Returns: the GType
 */
#define	G_TYPE_MAKE_FUNDAMENTAL(x)	((GType) ((x) << G_TYPE_FUNDAMENTAL_SHIFT))
/**
 * G_TYPE_RESERVED_GLIB_FIRST:
 * 
 * First fundamental type number to create a new fundamental type id with
 * G_TYPE_MAKE_FUNDAMENTAL() reserved for GLib.
 */
#define G_TYPE_RESERVED_GLIB_FIRST	(21)
/**
 * G_TYPE_RESERVED_GLIB_LAST:
 * 
 * Last fundamental type number reserved for GLib.
 */
#define G_TYPE_RESERVED_GLIB_LAST	(31)
/**
 * G_TYPE_RESERVED_BSE_FIRST:
 * 
 * First fundamental type number to create a new fundamental type id with
 * G_TYPE_MAKE_FUNDAMENTAL() reserved for BSE.
 */
#define G_TYPE_RESERVED_BSE_FIRST	(32)
/**
 * G_TYPE_RESERVED_BSE_LAST:
 * 
 * Last fundamental type number reserved for BSE.
 */
#define G_TYPE_RESERVED_BSE_LAST	(48)
/**
 * G_TYPE_RESERVED_USER_FIRST:
 * 
 * First available fundamental type number to create new fundamental 
 * type id with G_TYPE_MAKE_FUNDAMENTAL().
 */
#define G_TYPE_RESERVED_USER_FIRST	(49)


/* Type Checking Macros
 */
/**
 * G_TYPE_IS_FUNDAMENTAL:
 * @type: A #GType value.
 * 
 * Checks if @type is a fundamental type.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_FUNDAMENTAL(type)             ((type) <= G_TYPE_FUNDAMENTAL_MAX)
/**
 * G_TYPE_IS_DERIVED:
 * @type: A #GType value.
 * 
 * Checks if @type is derived (or in object-oriented terminology:
 * inherited) from another type (this holds true for all non-fundamental
 * types).
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_DERIVED(type)                 ((type) > G_TYPE_FUNDAMENTAL_MAX)
/**
 * G_TYPE_IS_INTERFACE:
 * @type: A #GType value.
 * 
 * Checks if @type is an interface type.
 * An interface type provides a pure API, the implementation
 * of which is provided by another type (which is then said to conform
 * to the interface).  GLib interfaces are somewhat analogous to Java
 * interfaces and C++ classes containing only pure virtual functions, 
 * with the difference that GType interfaces are not derivable (but see
 * g_type_interface_add_prerequisite() for an alternative).
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_INTERFACE(type)               (G_TYPE_FUNDAMENTAL (type) == G_TYPE_INTERFACE)
/**
 * G_TYPE_IS_CLASSED:
 * @type: A #GType value.
 * 
 * Checks if @type is a classed type.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_CLASSED(type)                 (g_type_test_flags ((type), G_TYPE_FLAG_CLASSED))
/**
 * G_TYPE_IS_INSTANTIATABLE:
 * @type: A #GType value.
 * 
 * Checks if @type can be instantiated.  Instantiation is the
 * process of creating an instance (object) of this type.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_INSTANTIATABLE(type)          (g_type_test_flags ((type), G_TYPE_FLAG_INSTANTIATABLE))
/**
 * G_TYPE_IS_DERIVABLE:
 * @type: A #GType value.
 * 
 * Checks if @type is a derivable type.  A derivable type can
 * be used as the base class of a flat (single-level) class hierarchy.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_DERIVABLE(type)               (g_type_test_flags ((type), G_TYPE_FLAG_DERIVABLE))
/**
 * G_TYPE_IS_DEEP_DERIVABLE:
 * @type: A #GType value.
 * 
 * Checks if @type is a deep derivable type.  A deep derivable type
 * can be used as the base class of a deep (multi-level) class hierarchy.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_DEEP_DERIVABLE(type)          (g_type_test_flags ((type), G_TYPE_FLAG_DEEP_DERIVABLE))
/**
 * G_TYPE_IS_ABSTRACT:
 * @type: A #GType value.
 * 
 * Checks if @type is an abstract type.  An abstract type can not be
 * instantiated and is normally used as an abstract base class for
 * derived classes.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_ABSTRACT(type)                (g_type_test_flags ((type), G_TYPE_FLAG_ABSTRACT))
/**
 * G_TYPE_IS_VALUE_ABSTRACT:
 * @type: A #GType value.
 * 
 * Checks if @type is an abstract value type.  An abstract value type introduces
 * a value table, but can't be used for g_value_init() and is normally used as
 * an abstract base type for derived value types.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_VALUE_ABSTRACT(type)          (g_type_test_flags ((type), G_TYPE_FLAG_VALUE_ABSTRACT))
/**
 * G_TYPE_IS_VALUE_TYPE:
 * @type: A #GType value.
 * 
 * Checks if @type is a value type and can be used with g_value_init(). 
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_IS_VALUE_TYPE(type)              (g_type_check_is_value_type (type))
/**
 * G_TYPE_HAS_VALUE_TABLE:
 * @type: A #GType value.
 * 
 * Checks if @type has a #GTypeValueTable.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_HAS_VALUE_TABLE(type)            (g_type_value_table_peek (type) != NULL)


/* Typedefs
 */
/**
 * GType:
 * 
 * A numerical value which represents the unique identifier of a registered
 * type.
 */
#if     GLIB_SIZEOF_SIZE_T != GLIB_SIZEOF_LONG || !defined __cplusplus
typedef gsize                           GType;
#else   /* for historic reasons, C++ links against gulong GTypes */
typedef gulong                          GType;
#endif
typedef struct _GValue                  GValue;
typedef union  _GTypeCValue             GTypeCValue;
typedef struct _GTypePlugin             GTypePlugin;
typedef struct _GTypeClass              GTypeClass;
typedef struct _GTypeInterface          GTypeInterface;
typedef struct _GTypeInstance           GTypeInstance;
typedef struct _GTypeInfo               GTypeInfo;
typedef struct _GTypeFundamentalInfo    GTypeFundamentalInfo;
typedef struct _GInterfaceInfo          GInterfaceInfo;
typedef struct _GTypeValueTable         GTypeValueTable;
typedef struct _GTypeQuery		GTypeQuery;


/* Basic Type Structures
 */
/**
 * GTypeClass:
 * 
 * An opaque structure used as the base of all classes.
 */
struct _GTypeClass
{
  /*< private >*/
  GType g_type;
};
/**
 * GTypeInstance:
 * 
 * An opaque structure used as the base of all type instances.
 */
struct _GTypeInstance
{
  /*< private >*/
  GTypeClass *g_class;
};
/**
 * GTypeInterface:
 * 
 * An opaque structure used as the base of all interface types.
 */
struct _GTypeInterface
{
  /*< private >*/
  GType g_type;         /* iface type */
  GType g_instance_type;
};
/**
 * GTypeQuery:
 * @type: the #GType value of the type.
 * @type_name: the name of the type.
 * @class_size: the size of the class structure.
 * @instance_size: the size of the instance structure.
 * 
 * A structure holding information for a specific type. It is
 * filled in by the g_type_query() function.
 */
struct _GTypeQuery
{
  GType		type;
  const gchar  *type_name;
  guint		class_size;
  guint		instance_size;
};


/* Casts, checks and accessors for structured types
 * usage of these macros is reserved to type implementations only
 */
/*< protected >*/
/**
 * G_TYPE_CHECK_INSTANCE:
 * @instance: Location of a #GTypeInstance structure.
 * 
 * Checks if @instance is a valid #GTypeInstance structure,
 * otherwise issues a warning and returns %FALSE.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_CHECK_INSTANCE(instance)				(_G_TYPE_CHI ((GTypeInstance*) (instance)))
/**
 * G_TYPE_CHECK_INSTANCE_CAST:
 * @instance: Location of a #GTypeInstance structure.
 * @g_type: The type to be returned.
 * @c_type: The corresponding C type of @g_type.
 * 
 * Checks that @instance is an instance of the type identified by @g_type
 * and issues a warning if this is not the case. Returns @instance casted 
 * to a pointer to @c_type.
 * 
 * This macro should only be used in type implementations.
 */
#define G_TYPE_CHECK_INSTANCE_CAST(instance, g_type, c_type)    (_G_TYPE_CIC ((instance), (g_type), c_type))
/**
 * G_TYPE_CHECK_INSTANCE_TYPE:
 * @instance: Location of a #GTypeInstance structure.
 * @g_type: The type to be checked
 * 
 * Checks if @instance is an instance of the type identified by @g_type.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_CHECK_INSTANCE_TYPE(instance, g_type)            (_G_TYPE_CIT ((instance), (g_type)))
/**
 * G_TYPE_INSTANCE_GET_CLASS:
 * @instance: Location of the #GTypeInstance structure.
 * @g_type: The #GType of the class to be returned.
 * @c_type: The C type of the class structure.
 * 
 * Get the class structure of a given @instance, casted
 * to a specified ancestor type @g_type of the instance.
 * 
 * Note that while calling a GInstanceInitFunc(), the class pointer gets
 * modified, so it might not always return the expected pointer.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: a pointer to the class structure
 */
#define G_TYPE_INSTANCE_GET_CLASS(instance, g_type, c_type)     (_G_TYPE_IGC ((instance), (g_type), c_type))
/**
 * G_TYPE_INSTANCE_GET_INTERFACE:
 * @instance: Location of the #GTypeInstance structure.
 * @g_type: The #GType of the interface to be returned.
 * @c_type: The C type of the interface structure.
 * 
 * Get the interface structure for interface @g_type of a given @instance.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: a pointer to the interface structure
 */
#define G_TYPE_INSTANCE_GET_INTERFACE(instance, g_type, c_type) (_G_TYPE_IGI ((instance), (g_type), c_type))
/**
 * G_TYPE_CHECK_CLASS_CAST:
 * @g_class: Location of a #GTypeClass structure.
 * @g_type: The type to be returned.
 * @c_type: The corresponding C type of class structure of @g_type.
 * 
 * Checks that @g_class is a class structure of the type identified by @g_type
 * and issues a warning if this is not the case. Returns @g_class casted 
 * to a pointer to @c_type.
 * 
 * This macro should only be used in type implementations.
 */
#define G_TYPE_CHECK_CLASS_CAST(g_class, g_type, c_type)        (_G_TYPE_CCC ((g_class), (g_type), c_type))
/**
 * G_TYPE_CHECK_CLASS_TYPE:
 * @g_class: Location of a #GTypeClass structure.
 * @g_type: The type to be checked.
 * 
 * Checks if @g_class is a class structure of the type identified by 
 * @g_type.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_CHECK_CLASS_TYPE(g_class, g_type)                (_G_TYPE_CCT ((g_class), (g_type)))
/**
 * G_TYPE_CHECK_VALUE:
 * @value: a #GValue
 * 
 * Checks if @value has been initialized to hold values
 * of a value type.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_CHECK_VALUE(value)				(_G_TYPE_CHV ((value)))
/**
 * G_TYPE_CHECK_VALUE_TYPE:
 * @value: a #GValue
 * @g_type: The type to be checked.
 * 
 * Checks if @value has been initialized to hold values
 * of type @g_type. 
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: %TRUE on success.
 */
#define G_TYPE_CHECK_VALUE_TYPE(value, g_type)			(_G_TYPE_CVH ((value), (g_type)))
/**
 * G_TYPE_FROM_INSTANCE:
 * @instance: Location of a valid #GTypeInstance structure.
 * 
 * Get the type identifier from a given @instance structure. 
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: the #GType
 */
#define G_TYPE_FROM_INSTANCE(instance)                          (G_TYPE_FROM_CLASS (((GTypeInstance*) (instance))->g_class))
/**
 * G_TYPE_FROM_CLASS:
 * @g_class: Location of a valid #GTypeClass structure.
 * 
 * Get the type identifier from a given @class structure.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: the #GType
 */
#define G_TYPE_FROM_CLASS(g_class)                              (((GTypeClass*) (g_class))->g_type)
/**
 * G_TYPE_FROM_INTERFACE:
 * @g_iface: Location of a valid #GTypeInterface structure.
 * 
 * Get the type identifier from a given @interface structure.
 * 
 * This macro should only be used in type implementations.
 *
 * Returns: the #GType
 */
#define G_TYPE_FROM_INTERFACE(g_iface)                          (((GTypeInterface*) (g_iface))->g_type)

/**
 * G_TYPE_INSTANCE_GET_PRIVATE:
 * @instance: the instance of a type deriving from @private_type.
 * @g_type: the type identifying which private data to retrieve.
 * @c_type: The C type for the private structure.
 * 
 * Gets the private structure for a particular type.
 * The private structure must have been registered in the
 * class_init function with g_type_class_add_private().
 * 
 * This macro should only be used in type implementations.
 * 
 * Since: 2.4
 * Returns: a pointer to the private data structure.
 */
#define G_TYPE_INSTANCE_GET_PRIVATE(instance, g_type, c_type)   ((c_type*) g_type_instance_get_private ((GTypeInstance*) (instance), (g_type)))


/**
 * GTypeDebugFlags:
 * @G_TYPE_DEBUG_NONE: Print no messages.
 * @G_TYPE_DEBUG_OBJECTS: Print messages about object bookkeeping.
 * @G_TYPE_DEBUG_SIGNALS: Print messages about signal emissions.
 * @G_TYPE_DEBUG_MASK: Mask covering all debug flags.
 * 
 * The <type>GTypeDebugFlags</type> enumeration values can be passed to
 * g_type_init_with_debug_flags() to trigger debugging messages during runtime.
 * Note that the messages can also be triggered by setting the
 * <envar>GOBJECT_DEBUG</envar> environment variable to a ':'-separated list of 
 * "objects" and "signals".
 */
typedef enum	/*< skip >*/
{
  G_TYPE_DEBUG_NONE	= 0,
  G_TYPE_DEBUG_OBJECTS	= 1 << 0,
  G_TYPE_DEBUG_SIGNALS	= 1 << 1,
  G_TYPE_DEBUG_MASK	= 0x03
} GTypeDebugFlags;


/* --- prototypes --- */
void                  g_type_init                    (void);
void                  g_type_init_with_debug_flags   (GTypeDebugFlags  debug_flags);
G_CONST_RETURN gchar* g_type_name                    (GType            type);
GQuark                g_type_qname                   (GType            type);
GType                 g_type_from_name               (const gchar     *name);
GType                 g_type_parent                  (GType            type);
guint                 g_type_depth                   (GType            type);
GType                 g_type_next_base               (GType            leaf_type,
						      GType            root_type);
gboolean              g_type_is_a                    (GType            type,
						      GType            is_a_type);
gpointer              g_type_class_ref               (GType            type);
gpointer              g_type_class_peek              (GType            type);
gpointer              g_type_class_peek_static       (GType            type);
void                  g_type_class_unref             (gpointer         g_class);
gpointer              g_type_class_peek_parent       (gpointer         g_class);
gpointer              g_type_interface_peek          (gpointer         instance_class,
						      GType            iface_type);
gpointer              g_type_interface_peek_parent   (gpointer         g_iface);

gpointer              g_type_default_interface_ref   (GType            g_type);
gpointer              g_type_default_interface_peek  (GType            g_type);
void                  g_type_default_interface_unref (gpointer         g_iface);

/* g_free() the returned arrays */
GType*                g_type_children                (GType            type,
						      guint           *n_children);
GType*                g_type_interfaces              (GType            type,
						      guint           *n_interfaces);

/* per-type _static_ data */
void                  g_type_set_qdata               (GType            type,
						      GQuark           quark,
						      gpointer         data);
gpointer              g_type_get_qdata               (GType            type,
						      GQuark           quark);
void		      g_type_query		     (GType	       type,
						      GTypeQuery      *query);


/* --- type registration --- */
/**
 * GBaseInitFunc:
 * @g_class: The #GTypeClass structure to initialize.
 * 
 * A callback function used by the type system to do base initialization
 * of the class structures of derived types. It is called as part of the
 * initialization process of all derived classes and should reallocate
 * or reset all dynamic class members copied over from the parent class.
 * For example, class members (such as strings) that are not sufficiently
 * handled by a plain memory copy of the parent class into the derived class
 * have to be altered. See GClassInitFunc() for a discussion of the class
 * intialization process.
 */
typedef void   (*GBaseInitFunc)              (gpointer         g_class);
/**
 * GBaseFinalizeFunc:
 * @g_class: The #GTypeClass structure to finalize.
 * 
 * A callback function used by the type system to finalize those portions
 * of a derived types class structure that were setup from the corresponding
 * GBaseInitFunc() function. Class finalization basically works the inverse
 * way in which class intialization is performed.
 * See GClassInitFunc() for a discussion of the class intialization process.
 */
typedef void   (*GBaseFinalizeFunc)          (gpointer         g_class);
/**
 * GClassInitFunc:
 * @g_class: The #GTypeClass structure to initialize.
 * @class_data: The @class_data member supplied via the #GTypeInfo structure.
 * 
 * A callback function used by the type system to initialize the class
 * of a specific type. This function should initialize all static class
 * members.
 * The initialization process of a class involves:
 * <itemizedlist>
 * <listitem><para>
 * 	1 - Copying common members from the parent class over to the
 * 	derived class structure.
 * </para></listitem>
 * <listitem><para>
 * 	2 -  Zero initialization of the remaining members not copied
 * 	over from the parent class.
 * </para></listitem>
 * <listitem><para>
 * 	3 - Invocation of the GBaseInitFunc() initializers of all parent
 * 	types and the class' type.
 * </para></listitem>
 * <listitem><para>
 * 	4 - Invocation of the class' GClassInitFunc() initializer.
 * </para></listitem>
 * </itemizedlist>
 * Since derived classes are partially initialized through a memory copy
 * of the parent class, the general rule is that GBaseInitFunc() and
 * GBaseFinalizeFunc() should take care of necessary reinitialization
 * and release of those class members that were introduced by the type
 * that specified these GBaseInitFunc()/GBaseFinalizeFunc().
 * GClassInitFunc() should only care about initializing static
 * class members, while dynamic class members (such as allocated strings
 * or reference counted resources) are better handled by a GBaseInitFunc()
 * for this type, so proper initialization of the dynamic class members
 * is performed for class initialization of derived types as well.
 * An example may help to correspond the intend of the different class
 * initializers:
 * 
 * |[
 * typedef struct {
 *   GObjectClass parent_class;
 *   gint         static_integer;
 *   gchar       *dynamic_string;
 * } TypeAClass;
 * static void
 * type_a_base_class_init (TypeAClass *class)
 * {
 *   class->dynamic_string = g_strdup ("some string");
 * }
 * static void
 * type_a_base_class_finalize (TypeAClass *class)
 * {
 *   g_free (class->dynamic_string);
 * }
 * static void
 * type_a_class_init (TypeAClass *class)
 * {
 *   class->static_integer = 42;
 * }
 * 
 * typedef struct {
 *   TypeAClass   parent_class;
 *   gfloat       static_float;
 *   GString     *dynamic_gstring;
 * } TypeBClass;
 * static void
 * type_b_base_class_init (TypeBClass *class)
 * {
 *   class->dynamic_gstring = g_string_new ("some other string");
 * }
 * static void
 * type_b_base_class_finalize (TypeBClass *class)
 * {
 *   g_string_free (class->dynamic_gstring);
 * }
 * static void
 * type_b_class_init (TypeBClass *class)
 * {
 *   class->static_float = 3.14159265358979323846;
 * }
 * ]|
 * Initialization of TypeBClass will first cause initialization of
 * TypeAClass (derived classes reference their parent classes, see
 * g_type_class_ref() on this).
 * Initialization of TypeAClass roughly involves zero-initializing its fields,
 * then calling its GBaseInitFunc() type_a_base_class_init() to allocate
 * its dynamic members (dynamic_string), and finally calling its GClassInitFunc()
 * type_a_class_init() to initialize its static members (static_integer).
 * The first step in the initialization process of TypeBClass is then
 * a plain memory copy of the contents of TypeAClass into TypeBClass and 
 * zero-initialization of the remaining fields in TypeBClass.
 * The dynamic members of TypeAClass within TypeBClass now need
 * reinitialization which is performed by calling type_a_base_class_init()
 * with an argument of TypeBClass.
 * After that, the GBaseInitFunc() of TypeBClass, type_b_base_class_init()
 * is called to allocate the dynamic members of TypeBClass (dynamic_gstring),
 * and finally the GClassInitFunc() of TypeBClass, type_b_class_init(),
 * is called to complete the initialization process with the static members
 * (static_float).
 * Corresponding finalization counter parts to the GBaseInitFunc() functions
 * have to be provided to release allocated resources at class finalization
 * time.
 */
typedef void   (*GClassInitFunc)             (gpointer         g_class,
					      gpointer         class_data);
/**
 * GClassFinalizeFunc:
 * @g_class: The #GTypeClass structure to finalize.
 * @class_data: The @class_data member supplied via the #GTypeInfo structure.
 * 
 * A callback function used by the type system to finalize a class.
 * This function is rarely needed, as dynamically allocated class resources
 * should be handled by GBaseInitFunc() and GBaseFinalizeFunc().
 * Also, specification of a GClassFinalizeFunc() in the #GTypeInfo
 * structure of a static type is invalid, because classes of static types
 * will never be finalized (they are artificially kept alive when their
 * reference count drops to zero).
 */
typedef void   (*GClassFinalizeFunc)         (gpointer         g_class,
					      gpointer         class_data);
/**
 * GInstanceInitFunc:
 * @instance: The instance to initialize.
 * @g_class: The class of the type the instance is created for.
 * 
 * A callback function used by the type system to initialize a new
 * instance of a type. This function initializes all instance members and
 * allocates any resources required by it.
 * Initialization of a derived instance involves calling all its parent
 * types instance initializers, so the class member of the instance
 * is altered during its initialization to always point to the class that
 * belongs to the type the current initializer was introduced for.
 */
typedef void   (*GInstanceInitFunc)          (GTypeInstance   *instance,
					      gpointer         g_class);
/**
 * GInterfaceInitFunc:
 * @g_iface: The interface structure to initialize.
 * @iface_data: The @interface_data supplied via the #GInterfaceInfo structure.
 * 
 * A callback function used by the type system to initialize a new
 * interface.  This function should initialize all internal data and
 * allocate any resources required by the interface.
 */
typedef void   (*GInterfaceInitFunc)         (gpointer         g_iface,
					      gpointer         iface_data);
/**
 * GInterfaceFinalizeFunc:
 * @g_iface: The interface structure to finalize.
 * @iface_data: The @interface_data supplied via the #GInterfaceInfo structure.
 * 
 * A callback function used by the type system to finalize an interface.
 * This function should destroy any internal data and release any resources
 * allocated by the corresponding GInterfaceInitFunc() function.
 */
typedef void   (*GInterfaceFinalizeFunc)     (gpointer         g_iface,
					      gpointer         iface_data);
/**
 * GTypeClassCacheFunc:
 * @cache_data: data that was given to the g_type_add_class_cache_func() call
 * @g_class: The #GTypeClass structure which is unreferenced
 * 
 * A callback function which is called when the reference count of a class 
 * drops to zero. It may use g_type_class_ref() to prevent the class from
 * being freed. You should not call g_type_class_unref() from a 
 * #GTypeClassCacheFunc function to prevent infinite recursion, use 
 * g_type_class_unref_uncached() instead.
 * 
 * The functions have to check the class id passed in to figure 
 * whether they actually want to cache the class of this type, since all
 * classes are routed through the same #GTypeClassCacheFunc chain.
 * 
 * Returns: %TRUE to stop further #GTypeClassCacheFunc<!-- -->s from being 
 *  called, %FALSE to continue.
 */
typedef gboolean (*GTypeClassCacheFunc)	     (gpointer	       cache_data,
					      GTypeClass      *g_class);
/**
 * GTypeInterfaceCheckFunc:
 * @check_data: data passed to g_type_add_interface_check().
 * @g_iface: the interface that has been initialized
 * 
 * A callback called after an interface vtable is initialized.
 * See g_type_add_interface_check().
 * 
 * Since: 2.4
 */
typedef void     (*GTypeInterfaceCheckFunc)  (gpointer	       check_data,
					      gpointer         g_iface);
/**
 * GTypeFundamentalFlags:
 * @G_TYPE_FLAG_CLASSED: Indicates a classed type.
 * @G_TYPE_FLAG_INSTANTIATABLE: Indicates an instantiable type (implies classed).
 * @G_TYPE_FLAG_DERIVABLE: Indicates a flat derivable type.
 * @G_TYPE_FLAG_DEEP_DERIVABLE: Indicates a deep derivable type (implies derivable).
 * 
 * Bit masks used to check or determine specific characteristics of a
 * fundamental type.
 */
typedef enum    /*< skip >*/
{
  G_TYPE_FLAG_CLASSED           = (1 << 0),
  G_TYPE_FLAG_INSTANTIATABLE    = (1 << 1),
  G_TYPE_FLAG_DERIVABLE         = (1 << 2),
  G_TYPE_FLAG_DEEP_DERIVABLE    = (1 << 3)
} GTypeFundamentalFlags;
/**
 * GTypeFlags:
 * @G_TYPE_FLAG_ABSTRACT: Indicates an abstract type. No instances can be
 *  created for an abstract type.
 * @G_TYPE_FLAG_VALUE_ABSTRACT: Indicates an abstract value type, i.e. a type
 *  that introduces a value table, but can't be used for
 *  g_value_init().
 * 
 * Bit masks used to check or determine characteristics of a type.
 */
typedef enum    /*< skip >*/
{
  G_TYPE_FLAG_ABSTRACT		= (1 << 4),
  G_TYPE_FLAG_VALUE_ABSTRACT	= (1 << 5)
} GTypeFlags;
/**
 * GTypeInfo:
 * @class_size: Size of the class structure (required for interface, classed and instantiatable types).
 * @base_init: Location of the base initialization function (optional).
 * @base_finalize: Location of the base finalization function (optional).
 * @class_init: Location of the class initialization function for
 *  classed and instantiatable types. Location of the default vtable 
 *  inititalization function for interface types. (optional) This function 
 *  is used both to fill in virtual functions in the class or default vtable, 
 *  and to do type-specific setup such as registering signals and object
 *  properties.
 * @class_finalize: Location of the class finalization function for
 *  classed and instantiatable types. Location fo the default vtable 
 *  finalization function for interface types. (optional)
 * @class_data: User-supplied data passed to the class init/finalize functions.
 * @instance_size: Size of the instance (object) structure (required for instantiatable types only).
 * @n_preallocs: Prior to GLib 2.10, it specified the number of pre-allocated (cached) instances to reserve memory for (0 indicates no caching). Since GLib 2.10, it is ignored, since instances are allocated with the <link linkend="glib-Memory-Slices">slice allocator</link> now.
 * @instance_init: Location of the instance initialization function (optional, for instantiatable types only).
 * @value_table: A #GTypeValueTable function table for generic handling of GValues of this type (usually only
 *  useful for fundamental types).
 * 
 * This structure is used to provide the type system with the information
 * required to initialize and destruct (finalize) a type's class and
 * its instances.
 * The initialized structure is passed to the g_type_register_static() function
 * (or is copied into the provided #GTypeInfo structure in the
 * g_type_plugin_complete_type_info()). The type system will perform a deep
 * copy of this structure, so its memory does not need to be persistent
 * across invocation of g_type_register_static().
 */
struct _GTypeInfo
{
  /* interface types, classed types, instantiated types */
  guint16                class_size;
  
  GBaseInitFunc          base_init;
  GBaseFinalizeFunc      base_finalize;
  
  /* interface types, classed types, instantiated types */
  GClassInitFunc         class_init;
  GClassFinalizeFunc     class_finalize;
  gconstpointer          class_data;
  
  /* instantiated types */
  guint16                instance_size;
  guint16                n_preallocs;
  GInstanceInitFunc      instance_init;
  
  /* value handling */
  const GTypeValueTable	*value_table;
};
/**
 * GTypeFundamentalInfo:
 * @type_flags: #GTypeFundamentalFlags describing the characteristics of the fundamental type
 * 
 * A structure that provides information to the type system which is
 * used specifically for managing fundamental types.  
 */
struct _GTypeFundamentalInfo
{
  GTypeFundamentalFlags  type_flags;
};
/**
 * GInterfaceInfo:
 * @interface_init: location of the interface initialization function
 * @interface_finalize: location of the interface finalization function
 * @interface_data: user-supplied data passed to the interface init/finalize functions
 * 
 * A structure that provides information to the type system which is
 * used specifically for managing interface types.
 */
struct _GInterfaceInfo
{
  GInterfaceInitFunc     interface_init;
  GInterfaceFinalizeFunc interface_finalize;
  gpointer               interface_data;
};
/**
 * GTypeValueTable:
 * @value_init: Default initialize @values contents by poking values
 *  directly into the value->data array. The data array of
 *  the #GValue passed into this function was zero-filled
 *  with <function>memset()</function>, so no care has to
 *  be taken to free any
 *  old contents. E.g. for the implementation of a string
 *  value that may never be %NULL, the implementation might
 *  look like:
 *  |[
 *  value->data[0].v_pointer = g_strdup ("");
 *  ]|
 * @value_free: Free any old contents that might be left in the
 *  data array of the passed in @value. No resources may
 *  remain allocated through the #GValue contents after
 *  this function returns. E.g. for our above string type:
 *  |[
 *  // only free strings without a specific flag for static storage
 *  if (!(value->data[1].v_uint & G_VALUE_NOCOPY_CONTENTS))
 *    g_free (value->data[0].v_pointer);
 *  ]|
 * @value_copy: @dest_value is a #GValue with zero-filled data section
 *  and @src_value is a properly setup #GValue of same or
 *  derived type.
 *  The purpose of this function is to copy the contents of
 *  @src_value into @dest_value in a way, that even after
 *  @src_value has been freed, the contents of @dest_value
 *  remain valid. String type example:
 *  |[
 *  dest_value->data[0].v_pointer = g_strdup (src_value->data[0].v_pointer);
 *  ]|
 * @value_peek_pointer: If the value contents fit into a pointer, such as objects
 *  or strings, return this pointer, so the caller can peek at
 *  the current contents. To extend on our above string example:
 *  |[
 *  return value->data[0].v_pointer;
 *  ]|
 * @collect_format: A string format describing how to collect the contents of
 *  this value bit-by-bit. Each character in the format represents
 *  an argument to be collected, and the characters themselves indicate
 *  the type of the argument. Currently supported arguments are:
 *  <variablelist>
 *  <varlistentry><term /><listitem><para>
 *  'i' - Integers. passed as collect_values[].v_int.
 *  </para></listitem></varlistentry>
 *  <varlistentry><term /><listitem><para>
 *  'l' - Longs. passed as collect_values[].v_long.
 *  </para></listitem></varlistentry>
 *  <varlistentry><term /><listitem><para>
 *  'd' - Doubles. passed as collect_values[].v_double.
 *  </para></listitem></varlistentry>
 *  <varlistentry><term /><listitem><para>
 *  'p' - Pointers. passed as collect_values[].v_pointer.
 *  </para></listitem></varlistentry>
 *  </variablelist>
 *  It should be noted that for variable argument list construction,
 *  ANSI C promotes every type smaller than an integer to an int, and
 *  floats to doubles. So for collection of short int or char, 'i'
 *  needs to be used, and for collection of floats 'd'.
 * @collect_value: The collect_value() function is responsible for converting the
 *  values collected from a variable argument list into contents
 *  suitable for storage in a GValue. This function should setup
 *  @value similar to value_init(); e.g. for a string value that
 *  does not allow %NULL pointers, it needs to either spew an error,
 *  or do an implicit conversion by storing an empty string.
 *  The @value passed in to this function has a zero-filled data
 *  array, so just like for value_init() it is guaranteed to not
 *  contain any old contents that might need freeing.
 *  @n_collect_values is exactly the string length of @collect_format,
 *  and @collect_values is an array of unions #GTypeCValue with
 *  length @n_collect_values, containing the collected values
 *  according to @collect_format.
 *  @collect_flags is an argument provided as a hint by the caller.
 *  It may contain the flag %G_VALUE_NOCOPY_CONTENTS indicating,
 *  that the collected value contents may be considered "static"
 *  for the duration of the @value lifetime.
 *  Thus an extra copy of the contents stored in @collect_values is
 *  not required for assignment to @value.
 *  For our above string example, we continue with:
 *  |[
 *  if (!collect_values[0].v_pointer)
 *    value->data[0].v_pointer = g_strdup ("");
 *  else if (collect_flags & G_VALUE_NOCOPY_CONTENTS)
 *  {
 *    value->data[0].v_pointer = collect_values[0].v_pointer;
 *    // keep a flag for the value_free() implementation to not free this string
 *    value->data[1].v_uint = G_VALUE_NOCOPY_CONTENTS;
 *  }
 *  else
 *    value->data[0].v_pointer = g_strdup (collect_values[0].v_pointer);
 *  return NULL;
 *  ]|
 *  It should be noted, that it is generally a bad idea to follow the
 *  #G_VALUE_NOCOPY_CONTENTS hint for reference counted types. Due to
 *  reentrancy requirements and reference count assertions performed
 *  by the #GSignal code, reference counts should always be incremented
 *  for reference counted contents stored in the value->data array.
 *  To deviate from our string example for a moment, and taking a look
 *  at an exemplary implementation for collect_value() of #GObject:
 *  |[
 *  if (collect_values[0].v_pointer)
 *  {
 *    GObject *object = G_OBJECT (collect_values[0].v_pointer);
 *    // never honour G_VALUE_NOCOPY_CONTENTS for ref-counted types
 *    value->data[0].v_pointer = g_object_ref (object);
 *    return NULL;
 *  }
 *  else
 *    return g_strdup_printf ("Object passed as invalid NULL pointer");
 *  }
 *  ]|
 *  The reference count for valid objects is always incremented,
 *  regardless of @collect_flags. For invalid objects, the example
 *  returns a newly allocated string without altering @value.
 *  Upon success, collect_value() needs to return %NULL. If, however,
 *  an error condition occurred, collect_value() may spew an
 *  error by returning a newly allocated non-%NULL string, giving
 *  a suitable description of the error condition.
 *  The calling code makes no assumptions about the @value
 *  contents being valid upon error returns, @value
 *  is simply thrown away without further freeing. As such, it is
 *  a good idea to not allocate #GValue contents, prior to returning
 *  an error, however, collect_values() is not obliged to return
 *  a correctly setup @value for error returns, simply because
 *  any non-%NULL return is considered a fatal condition so further
 *  program behaviour is undefined.
 * @lcopy_format: Format description of the arguments to collect for @lcopy_value,
 *  analogous to @collect_format. Usually, @lcopy_format string consists
 *  only of 'p's to provide lcopy_value() with pointers to storage locations.
 * @lcopy_value: This function is responsible for storing the @value contents into
 *  arguments passed through a variable argument list which got
 *  collected into @collect_values according to @lcopy_format.
 *  @n_collect_values equals the string length of @lcopy_format,
 *  and @collect_flags may contain %G_VALUE_NOCOPY_CONTENTS.
 *  In contrast to collect_value(), lcopy_value() is obliged to
 *  always properly support %G_VALUE_NOCOPY_CONTENTS.
 *  Similar to collect_value() the function may prematurely abort
 *  by returning a newly allocated string describing an error condition.
 *  To complete the string example:
 *  |[
 *  gchar **string_p = collect_values[0].v_pointer;
 *  if (!string_p)
 *    return g_strdup_printf ("string location passed as NULL");
 *  if (collect_flags & G_VALUE_NOCOPY_CONTENTS)
 *    *string_p = value->data[0].v_pointer;
 *  else
 *    *string_p = g_strdup (value->data[0].v_pointer);
 *  ]|
 *  And an illustrative version of lcopy_value() for
 *  reference-counted types:
 *  |[
 *  GObject **object_p = collect_values[0].v_pointer;
 *  if (!object_p)
 *    return g_strdup_printf ("object location passed as NULL");
 *  if (!value->data[0].v_pointer)
 *    *object_p = NULL;
 *  else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) // always honour
 *    *object_p = value->data[0].v_pointer;
 *  else
 *    *object_p = g_object_ref (value->data[0].v_pointer);
 *  return NULL;
 *  ]|
 * 
 * The #GTypeValueTable provides the functions required by the #GValue implementation,
 * to serve as a container for values of a type.
 */

struct _GTypeValueTable
{
  void     (*value_init)         (GValue       *value);
  void     (*value_free)         (GValue       *value);
  void     (*value_copy)         (const GValue *src_value,
				  GValue       *dest_value);
  /* varargs functionality (optional) */
  gpointer (*value_peek_pointer) (const GValue *value);
  gchar	    *collect_format;
  gchar*   (*collect_value)      (GValue       *value,
				  guint         n_collect_values,
				  GTypeCValue  *collect_values,
				  guint		collect_flags);
  gchar	    *lcopy_format;
  gchar*   (*lcopy_value)        (const GValue *value,
				  guint         n_collect_values,
				  GTypeCValue  *collect_values,
				  guint		collect_flags);
};
GType g_type_register_static		(GType			     parent_type,
					 const gchar		    *type_name,
					 const GTypeInfo	    *info,
					 GTypeFlags		     flags);
GType g_type_register_static_simple     (GType                       parent_type,
					 const gchar                *type_name,
					 guint                       class_size,
					 GClassInitFunc              class_init,
					 guint                       instance_size,
					 GInstanceInitFunc           instance_init,
					 GTypeFlags	             flags);
  
GType g_type_register_dynamic		(GType			     parent_type,
					 const gchar		    *type_name,
					 GTypePlugin		    *plugin,
					 GTypeFlags		     flags);
GType g_type_register_fundamental	(GType			     type_id,
					 const gchar		    *type_name,
					 const GTypeInfo	    *info,
					 const GTypeFundamentalInfo *finfo,
					 GTypeFlags		     flags);
void  g_type_add_interface_static	(GType			     instance_type,
					 GType			     interface_type,
					 const GInterfaceInfo	    *info);
void  g_type_add_interface_dynamic	(GType			     instance_type,
					 GType			     interface_type,
					 GTypePlugin		    *plugin);
void  g_type_interface_add_prerequisite (GType			     interface_type,
					 GType			     prerequisite_type);
GType*g_type_interface_prerequisites    (GType                       interface_type,
					 guint                      *n_prerequisites);
void     g_type_class_add_private       (gpointer                    g_class,
                                         gsize                       private_size);
gpointer g_type_instance_get_private    (GTypeInstance              *instance,
                                         GType                       private_type);


/* --- GType boilerplate --- */
/**
 * G_DEFINE_TYPE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words 
 *  separated by '_'.
 * @T_P: The #GType of the parent type.
 * 
 * A convenience macro for type implementations, which declares a 
 * class initialization function, an instance initialization function (see #GTypeInfo for information about 
 * these) and a static variable named @t_n<!-- -->_parent_class pointing to the parent class. Furthermore, it defines 
 * a *_get_type() function. See G_DEFINE_TYPE_EXTENDED() for an example.
 * 
 * Since: 2.4
 */
#define G_DEFINE_TYPE(TN, t_n, T_P)			    G_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, 0, {})
/**
 * G_DEFINE_TYPE_WITH_CODE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type in lowercase, with words separated by '_'.
 * @T_P: The #GType of the parent type.
 * @_C_: Custom code that gets inserted in the *_get_type() function.
 * 
 * A convenience macro for type implementations.  
 * Similar to G_DEFINE_TYPE(), but allows you to insert custom code into the 
 * *_get_type() function, e.g. interface implementations via G_IMPLEMENT_INTERFACE().
 * See G_DEFINE_TYPE_EXTENDED() for an example.
 * 
 * Since: 2.4
 */
#define G_DEFINE_TYPE_WITH_CODE(TN, t_n, T_P, _C_)	    _G_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, 0) {_C_;} _G_DEFINE_TYPE_EXTENDED_END()
/**
 * G_DEFINE_ABSTRACT_TYPE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words 
 *  separated by '_'.
 * @T_P: The #GType of the parent type.
 * 
 * A convenience macro for type implementations. 
 * Similar to G_DEFINE_TYPE(), but defines an abstract type. 
 * See G_DEFINE_TYPE_EXTENDED() for an example.
 * 
 * Since: 2.4
 */
#define G_DEFINE_ABSTRACT_TYPE(TN, t_n, T_P)		    G_DEFINE_TYPE_EXTENDED (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT, {})
/**
 * G_DEFINE_ABSTRACT_TYPE_WITH_CODE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words 
 *  separated by '_'.
 * @T_P: The #GType of the parent type.
 * @_C_: Custom code that gets inserted in the @type_name_get_type() function.
 * 
 * A convenience macro for type implementations.
 * Similar to G_DEFINE_TYPE_WITH_CODE(), but defines an abstract type and allows you to 
 * insert custom code into the *_get_type() function, e.g. interface implementations 
 * via G_IMPLEMENT_INTERFACE(). See G_DEFINE_TYPE_EXTENDED() for an example.
 * 
 * Since: 2.4
 */
#define G_DEFINE_ABSTRACT_TYPE_WITH_CODE(TN, t_n, T_P, _C_) _G_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, G_TYPE_FLAG_ABSTRACT) {_C_;} _G_DEFINE_TYPE_EXTENDED_END()
/**
 * G_DEFINE_TYPE_EXTENDED:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words
 *    separated by '_'.
 * @T_P: The #GType of the parent type.
 * @_f_: #GTypeFlags to pass to g_type_register_static()
 * @_C_: Custom code that gets inserted in the *_get_type() function.
 *
 * The most general convenience macro for type implementations, on which
 * G_DEFINE_TYPE(), etc are based.
 *
 * |[
 * G_DEFINE_TYPE_EXTENDED (GtkGadget,
 *                         gtk_gadget,
 *                         GTK_TYPE_WIDGET,
 *                         0,
 *                         G_IMPLEMENT_INTERFACE (TYPE_GIZMO,
 *                                                gtk_gadget_gizmo_init));
 * ]|
 * expands to
 * |[
 * static void     gtk_gadget_init       (GtkGadget      *self);
 * static void     gtk_gadget_class_init (GtkGadgetClass *klass);
 * static gpointer gtk_gadget_parent_class = NULL;
 * static void     gtk_gadget_class_intern_init (gpointer klass)
 * {
 *   gtk_gadget_parent_class = g_type_class_peek_parent (klass);
 *   gtk_gadget_class_init ((GtkGadgetClass*) klass);
 * }
 *
 * GType
 * gtk_gadget_get_type (void)
 * {
 *   static volatile gsize g_define_type_id__volatile = 0;
 *   if (g_once_init_enter (&g_define_type_id__volatile))
 *     {
 *       GType g_define_type_id =
 *         g_type_register_static_simple (GTK_TYPE_WIDGET,
 *                                        g_intern_static_string ("GtkGadget"),
 *                                        sizeof (GtkGadgetClass),
 *                                        (GClassInitFunc) gtk_gadget_class_intern_init,
 *                                        sizeof (GtkGadget),
 *                                        (GInstanceInitFunc) gtk_gadget_init,
 *                                        (GTypeFlags) flags);
 *       {
 *         static const GInterfaceInfo g_implement_interface_info = {
 *           (GInterfaceInitFunc) gtk_gadget_gizmo_init
 *         };
 *         g_type_add_interface_static (g_define_type_id, TYPE_GIZMO, &g_implement_interface_info);
 *       }
 *       g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
 *     }
 *   return g_define_type_id__volatile;
 * }
 * ]|
 * The only pieces which have to be manually provided are the definitions of
 * the instance and class structure and the definitions of the instance and
 * class init functions.
 *
 * Since: 2.4
 */
#define G_DEFINE_TYPE_EXTENDED(TN, t_n, T_P, _f_, _C_)	    _G_DEFINE_TYPE_EXTENDED_BEGIN (TN, t_n, T_P, _f_) {_C_;} _G_DEFINE_TYPE_EXTENDED_END()

/**
 * G_DEFINE_INTERFACE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words separated by '_'.
 * @T_P: The #GType of the prerequisite type for the interface, or 0
 * (%G_TYPE_INVALID) for no prerequisite type.
 *
 * A convenience macro for #GTypeInterface definitions, which declares
 * a default vtable initialization function and defines a *_get_type()
 * function.
 *
 * The macro expects the interface initialization function to have the
 * name <literal>t_n ## _default_init</literal>, and the interface
 * structure to have the name <literal>TN ## Interface</literal>.
 *
 * Since: 2.24
 */
#define G_DEFINE_INTERFACE(TN, t_n, T_P)		    G_DEFINE_INTERFACE_WITH_CODE(TN, t_n, T_P, ;)

/**
 * G_DEFINE_INTERFACE_WITH_CODE:
 * @TN: The name of the new type, in Camel case.
 * @t_n: The name of the new type, in lowercase, with words separated by '_'.
 * @T_P: The #GType of the prerequisite type for the interface, or 0
 * (%G_TYPE_INVALID) for no prerequisite type.
 * @_C_: Custom code that gets inserted in the *_get_type() function.
 *
 * A convenience macro for #GTypeInterface definitions. Similar to
 * G_DEFINE_INTERFACE(), but allows you to insert custom code into the
 * *_get_type() function, e.g. additional interface implementations
 * via G_IMPLEMENT_INTERFACE(), or additional prerequisite types. See
 * G_DEFINE_TYPE_EXTENDED() for a similar example using
 * G_DEFINE_TYPE_WITH_CODE().
 *
 * Since: 2.24
 */
#define G_DEFINE_INTERFACE_WITH_CODE(TN, t_n, T_P, _C_)     _G_DEFINE_INTERFACE_EXTENDED_BEGIN(TN, t_n, T_P) {_C_;} _G_DEFINE_INTERFACE_EXTENDED_END()

/**
 * G_IMPLEMENT_INTERFACE:
 * @TYPE_IFACE: The #GType of the interface to add
 * @iface_init: The interface init function
 *
 * A convenience macro to ease interface addition in the @_C_ section
 * of G_DEFINE_TYPE_WITH_CODE() or G_DEFINE_ABSTRACT_TYPE_WITH_CODE().
 * See G_DEFINE_TYPE_EXTENDED() for an example.
 *
 * Note that this macro can only be used together with the G_DEFINE_TYPE_*
 * macros, since it depends on variable names from those macros.
 *
 * Since: 2.4
 */
#define G_IMPLEMENT_INTERFACE(TYPE_IFACE, iface_init)       { \
  const GInterfaceInfo g_implement_interface_info = { \
    (GInterfaceInitFunc) iface_init, NULL, NULL \
  }; \
  g_type_add_interface_static (g_define_type_id, TYPE_IFACE, &g_implement_interface_info); \
}

#define _G_DEFINE_TYPE_EXTENDED_BEGIN(TypeName, type_name, TYPE_PARENT, flags) \
\
static void     type_name##_init              (TypeName        *self); \
static void     type_name##_class_init        (TypeName##Class *klass); \
static gpointer type_name##_parent_class = NULL; \
static void     type_name##_class_intern_init (gpointer klass) \
{ \
  type_name##_parent_class = g_type_class_peek_parent (klass); \
  type_name##_class_init ((TypeName##Class*) klass); \
} \
\
GType \
type_name##_get_type (void) \
{ \
  static volatile gsize g_define_type_id__volatile = 0; \
  if (g_once_init_enter (&g_define_type_id__volatile))  \
    { \
      GType g_define_type_id = \
        g_type_register_static_simple (TYPE_PARENT, \
                                       g_intern_static_string (#TypeName), \
                                       sizeof (TypeName##Class), \
                                       (GClassInitFunc) type_name##_class_intern_init, \
                                       sizeof (TypeName), \
                                       (GInstanceInitFunc) type_name##_init, \
                                       (GTypeFlags) flags); \
      { /* custom code follows */
#define _G_DEFINE_TYPE_EXTENDED_END()	\
        /* following custom code */	\
      }					\
      g_once_init_leave (&g_define_type_id__volatile, g_define_type_id); \
    }					\
  return g_define_type_id__volatile;	\
} /* closes type_name##_get_type() */

#define _G_DEFINE_INTERFACE_EXTENDED_BEGIN(TypeName, type_name, TYPE_PREREQ) \
\
static void     type_name##_default_init        (TypeName##Interface *klass); \
\
GType \
type_name##_get_type (void) \
{ \
  static volatile gsize g_define_type_id__volatile = 0; \
  if (g_once_init_enter (&g_define_type_id__volatile))  \
    { \
      GType g_define_type_id = \
        g_type_register_static_simple (G_TYPE_INTERFACE, \
                                       g_intern_static_string (#TypeName), \
                                       sizeof (TypeName##Interface), \
                                       (GClassInitFunc)type_name##_default_init, \
                                       0, \
                                       (GInstanceInitFunc)NULL, \
                                       (GTypeFlags) 0); \
      if (TYPE_PREREQ) \
        g_type_interface_add_prerequisite (g_define_type_id, TYPE_PREREQ); \
      { /* custom code follows */
#define _G_DEFINE_INTERFACE_EXTENDED_END()	\
        /* following custom code */		\
      }						\
      g_once_init_leave (&g_define_type_id__volatile, g_define_type_id); \
    }						\
  return g_define_type_id__volatile;			\
} /* closes type_name##_get_type() */

/* --- protected (for fundamental type implementations) --- */
GTypePlugin*	 g_type_get_plugin		(GType		     type);
GTypePlugin*	 g_type_interface_get_plugin	(GType		     instance_type,
						 GType               interface_type);
GType		 g_type_fundamental_next	(void);
GType		 g_type_fundamental		(GType		     type_id);
GTypeInstance*   g_type_create_instance         (GType               type);
void             g_type_free_instance           (GTypeInstance      *instance);

void		 g_type_add_class_cache_func    (gpointer	     cache_data,
						 GTypeClassCacheFunc cache_func);
void		 g_type_remove_class_cache_func (gpointer	     cache_data,
						 GTypeClassCacheFunc cache_func);
void             g_type_class_unref_uncached    (gpointer            g_class);

void             g_type_add_interface_check     (gpointer	         check_data,
						 GTypeInterfaceCheckFunc check_func);
void             g_type_remove_interface_check  (gpointer	         check_data,
						 GTypeInterfaceCheckFunc check_func);

GTypeValueTable* g_type_value_table_peek        (GType		     type);


/*< private >*/
gboolean	 g_type_check_instance          (GTypeInstance      *instance) G_GNUC_PURE;
GTypeInstance*   g_type_check_instance_cast     (GTypeInstance      *instance,
						 GType               iface_type);
gboolean         g_type_check_instance_is_a	(GTypeInstance      *instance,
						 GType               iface_type) G_GNUC_PURE;
GTypeClass*      g_type_check_class_cast        (GTypeClass         *g_class,
						 GType               is_a_type);
gboolean         g_type_check_class_is_a        (GTypeClass         *g_class,
						 GType               is_a_type) G_GNUC_PURE;
gboolean	 g_type_check_is_value_type     (GType		     type) G_GNUC_CONST;
gboolean	 g_type_check_value             (GValue		    *value) G_GNUC_PURE;
gboolean	 g_type_check_value_holds	(GValue		    *value,
						 GType		     type) G_GNUC_PURE;
gboolean         g_type_test_flags              (GType               type,
						 guint               flags) G_GNUC_CONST;


/* --- debugging functions --- */
G_CONST_RETURN gchar* g_type_name_from_instance	(GTypeInstance	*instance);
G_CONST_RETURN gchar* g_type_name_from_class	(GTypeClass	*g_class);


/* --- internal functions --- */
G_GNUC_INTERNAL void    g_value_c_init          (void); /* sync with gvalue.c */
G_GNUC_INTERNAL void    g_value_types_init      (void); /* sync with gvaluetypes.c */
G_GNUC_INTERNAL void    g_enum_types_init       (void); /* sync with genums.c */
G_GNUC_INTERNAL void    g_param_type_init       (void); /* sync with gparam.c */
G_GNUC_INTERNAL void    g_boxed_type_init       (void); /* sync with gboxed.c */
G_GNUC_INTERNAL void    g_object_type_init      (void); /* sync with gobject.c */
G_GNUC_INTERNAL void    g_param_spec_types_init (void); /* sync with gparamspecs.c */
G_GNUC_INTERNAL void    g_value_transforms_init (void); /* sync with gvaluetransform.c */
G_GNUC_INTERNAL void    g_signal_init           (void); /* sync with gsignal.c */


/* --- implementation bits --- */
#ifndef G_DISABLE_CAST_CHECKS
#  define _G_TYPE_CIC(ip, gt, ct) \
    ((ct*) g_type_check_instance_cast ((GTypeInstance*) ip, gt))
#  define _G_TYPE_CCC(cp, gt, ct) \
    ((ct*) g_type_check_class_cast ((GTypeClass*) cp, gt))
#else /* G_DISABLE_CAST_CHECKS */
#  define _G_TYPE_CIC(ip, gt, ct)       ((ct*) ip)
#  define _G_TYPE_CCC(cp, gt, ct)       ((ct*) cp)
#endif /* G_DISABLE_CAST_CHECKS */
#define _G_TYPE_CHI(ip)			(g_type_check_instance ((GTypeInstance*) ip))
#define _G_TYPE_CHV(vl)			(g_type_check_value ((GValue*) vl))
#define _G_TYPE_IGC(ip, gt, ct)         ((ct*) (((GTypeInstance*) ip)->g_class))
#define _G_TYPE_IGI(ip, gt, ct)         ((ct*) g_type_interface_peek (((GTypeInstance*) ip)->g_class, gt))
#ifdef	__GNUC__
#  define _G_TYPE_CIT(ip, gt)             (G_GNUC_EXTENSION ({ \
  GTypeInstance *__inst = (GTypeInstance*) ip; GType __t = gt; gboolean __r; \
  if (!__inst) \
    __r = FALSE; \
  else if (__inst->g_class && __inst->g_class->g_type == __t) \
    __r = TRUE; \
  else \
    __r = g_type_check_instance_is_a (__inst, __t); \
  __r; \
}))
#  define _G_TYPE_CCT(cp, gt)             (G_GNUC_EXTENSION ({ \
  GTypeClass *__class = (GTypeClass*) cp; GType __t = gt; gboolean __r; \
  if (!__class) \
    __r = FALSE; \
  else if (__class->g_type == __t) \
    __r = TRUE; \
  else \
    __r = g_type_check_class_is_a (__class, __t); \
  __r; \
}))
#  define _G_TYPE_CVH(vl, gt)             (G_GNUC_EXTENSION ({ \
  GValue *__val = (GValue*) vl; GType __t = gt; gboolean __r; \
  if (!__val) \
    __r = FALSE; \
  else if (__val->g_type == __t)		\
    __r = TRUE; \
  else \
    __r = g_type_check_value_holds (__val, __t); \
  __r; \
}))
#else  /* !__GNUC__ */
#  define _G_TYPE_CIT(ip, gt)             (g_type_check_instance_is_a ((GTypeInstance*) ip, gt))
#  define _G_TYPE_CCT(cp, gt)             (g_type_check_class_is_a ((GTypeClass*) cp, gt))
#  define _G_TYPE_CVH(vl, gt)             (g_type_check_value_holds ((GValue*) vl, gt))
#endif /* !__GNUC__ */
/**
 * G_TYPE_FLAG_RESERVED_ID_BIT:
 * 
 * A bit in the type number that's supposed to be left untouched.
 */
#define	G_TYPE_FLAG_RESERVED_ID_BIT	((GType) (1 << 0))
extern GTypeDebugFlags			_g_type_debug_flags;

G_END_DECLS

#endif /* __G_TYPE_H__ */
