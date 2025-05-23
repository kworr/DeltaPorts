# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	libcxx
PORTVERSION=	18.1.8
DISTNAME=	llvm-project-${PORTVERSION}.src
PKGNAMEPREFIX=	llvm${LLVM_VERSION}-
CATEGORIES=	devel
MASTER_SITES=	http://releases.llvm.org/${PORTVERSION}/ \
		 https://github.com/llvm/llvm-project/releases/download/llvmorg-${PORTVERSION}/

MAINTAINER=	tuxillo@quantumachine.net
COMMENT?=	LLVM C++ standard library with c++11 support

CONFLICTS=     libcxx-${LLVM_VERSION}*

USES=		cmake llvm:18 tar:xz

LICENSE_GROUP=	MIT UIUC
LICENSE_NAME_UIUC=	University of Illinois/NCSA Open Source License
LICENSE_PERMS_UIUC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

# for now we're going to try and use libc++abi as the runtime
# but we can leave this cxxrt references empty for future reference
CXXRT_INCS=
CXXRT_LIB=
EXTRALIB=	${LOCALBASE}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/libc++abi.so

PLIST_SUB+=	LLVM_DEFAULT=${LLVM_DEFAULT} \
		PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

# Force build with llvm
LLVM_DEFAULT=		18
USE_CLANG_FALLBACK=     18

USE_LDCONFIG=	${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib

CMAKE_SOURCE_PATH=	${WRKSRC}/runtimes
CMAKE_INSTALL_PREFIX=	${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}

CMAKE_ARGS=	-DLIBCXX_CXX_ABI=libcxxabi
CMAKE_ARGS+=	-DLIBCXX_INCLUDE_BENCHMARKS=OFF
CMAKE_ARGS+=	-DLIBCXXABI_USE_LLVM_UNWINDER=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi"

post-install:
	${LN} -sf c++/v1 ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/include/c++/v1/tr1
	${RM} ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/libc++.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/c++/
	${ECHO} 'GROUP ( ${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/libc++.so.1 ${CXXRT_LIB} ${EXTRALIB})' > ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/libc++.so
	${ECHO} 'GROUP ( ${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/libc++.so.1 ${CXXRT_LIB} ${EXTRALIB})' > ${STAGEDIR}${PREFIX}/llvm${LLVM_DEFAULT}/${PORTNAME}/lib/c++/libstdc++.so

.include <bsd.port.mk>
