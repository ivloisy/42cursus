<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'ivloisy' );

/** Database password */
define( 'DB_PASSWORD', 'ivloisy' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         't+oSgX7c?[xgP*cm7n%v+!BW5+=viH-Brxp}8zM>e8H}#xNi>B=,q`3xUMtvkQ!H' );
define( 'SECURE_AUTH_KEY',  ']Ma~5-{&;b#|yuCGbj:1}Gqm{}Wxke r)x!E^>:).kHeX>%}gSK%PvIX/4A6kpZB' );
define( 'LOGGED_IN_KEY',    'ADHNqdJi]~>cN&/H/8dCu0UKT(AG.uS=kAXYqW[{DdOxtZ? PPA~o-8{04^]yxpD' );
define( 'NONCE_KEY',        'ovFg.ly*hli]rR88Ix[je,mi&]+2z2jK$~]o^&Y6{hTD)[Oav[AXl*2d}H4Lih(,' );
define( 'AUTH_SALT',        '+lK,x_:Ec2K<z!4@Pg:$73&5)njpOCh`>,tf~=Gu`,9t]S9DP6,K:yq{#|+0sPSo' );
define( 'SECURE_AUTH_SALT', '7G%WVk)!9qN0[MUqJ8/0DP$+*43;Xb93)D4PJ8Xa] [;2Df+$an)QII`3W<_3RV9' );
define( 'LOGGED_IN_SALT',   'Ef.]T/mtR>C:`Bq,:71/1NYO?~2.F!&^:,RSk?@0feA7^iA{T7zub9^nS3YR`$ww' );
define( 'NONCE_SALT',       'PV7xB/eUB@Xq@kXP8;/!k%fUV%in{N*GH]c_RMbfMMN-_Nof[&KE&F0+%)WBb_5m' );

/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
