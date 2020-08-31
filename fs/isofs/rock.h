/* SPDX-License-Identifier: GPL-2.0 */
/*
 * These structs are used by the system-use-sharing protocol, in which the
 * Rock Ridge extensions are embedded.  It is quite possible that other
 * extensions are present on the disk, and this is fine as long as they
 * all use SUSP
 */

struct SU_SP_s {
	unsigned char magic[2];
	unsigned char skip;
} __attribute__ ((packed));

struct SU_CE_s {
	char extent[8];
	char offset[8];
	char size[8];
};

struct SU_ER_s {
<<<<<<< HEAD
	unsigned char len_id;
	unsigned char len_des;
	unsigned char len_src;
	unsigned char ext_ver;
	char data[];
=======
	__u8 len_id;
	__u8 len_des;
	__u8 len_src;
	__u8 ext_ver;
	__u8 data[];
>>>>>>> 5b4c91815378 (UPSTREAM: fs: Replace zero-length array with flexible-array member)
} __attribute__ ((packed));

struct RR_RR_s {
	char flags[1];
} __attribute__ ((packed));

struct RR_PX_s {
	char mode[8];
	char n_links[8];
	char uid[8];
	char gid[8];
};

struct RR_PN_s {
	char dev_high[8];
	char dev_low[8];
};

struct SL_component {
<<<<<<< HEAD
	unsigned char flags;
	unsigned char len;
	char text[];
=======
	__u8 flags;
	__u8 len;
	__u8 text[];
>>>>>>> 5b4c91815378 (UPSTREAM: fs: Replace zero-length array with flexible-array member)
} __attribute__ ((packed));

struct RR_SL_s {
	unsigned char flags;
	struct SL_component link;
} __attribute__ ((packed));

struct RR_NM_s {
<<<<<<< HEAD
	unsigned char flags;
=======
	__u8 flags;
>>>>>>> 5b4c91815378 (UPSTREAM: fs: Replace zero-length array with flexible-array member)
	char name[];
} __attribute__ ((packed));

struct RR_CL_s {
	char location[8];
};

struct RR_PL_s {
	char location[8];
};

struct stamp {
	__u8 time[7];		/* actually 6 unsigned, 1 signed */
} __attribute__ ((packed));

struct RR_TF_s {
<<<<<<< HEAD
	char flags;
=======
	__u8 flags;
>>>>>>> 5b4c91815378 (UPSTREAM: fs: Replace zero-length array with flexible-array member)
	struct stamp times[];	/* Variable number of these beasts */
} __attribute__ ((packed));

/* Linux-specific extension for transparent decompression */
struct RR_ZF_s {
	char algorithm[2];
	char parms[2];
	char real_size[8];
};

/*
 * These are the bits and their meanings for flags in the TF structure.
 */
#define TF_CREATE 1
#define TF_MODIFY 2
#define TF_ACCESS 4
#define TF_ATTRIBUTES 8
#define TF_BACKUP 16
#define TF_EXPIRATION 32
#define TF_EFFECTIVE 64
#define TF_LONG_FORM 128

struct rock_ridge {
	char signature[2];
	unsigned char len;
	unsigned char version;
	union {
		struct SU_SP_s SP;
		struct SU_CE_s CE;
		struct SU_ER_s ER;
		struct RR_RR_s RR;
		struct RR_PX_s PX;
		struct RR_PN_s PN;
		struct RR_SL_s SL;
		struct RR_NM_s NM;
		struct RR_CL_s CL;
		struct RR_PL_s PL;
		struct RR_TF_s TF;
		struct RR_ZF_s ZF;
	} u;
};

#define RR_PX 1			/* POSIX attributes */
#define RR_PN 2			/* POSIX devices */
#define RR_SL 4			/* Symbolic link */
#define RR_NM 8			/* Alternate Name */
#define RR_CL 16		/* Child link */
#define RR_PL 32		/* Parent link */
#define RR_RE 64		/* Relocation directory */
#define RR_TF 128		/* Timestamps */
