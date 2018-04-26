FROM fedora:27

LABEL \
	org.label-schema.schema-version = "2.1.0" \
	org.label-schema.name = "CIM2Mod" \
	org.label-schema.license = "MPL" \
	org.label-schema.vendor = "Institute for Automation of Complex Power Systems, RWTH Aachen University" \
	org.label-schema.author.name = "Lukas Razik" \
	org.label-schema.author.email = "lrazik@eonerc.rwth-aachen.org" \
	org.label-schema.vcs-url = "https://git.rwth-aachen.de/acs/core/cim/CIM2Mod"

RUN dnf -y update

# Toolchain
RUN dnf -y install \
	git \
	gcc-c++ \
	make cmake \
	doxygen graphviz \
	rpmdevtools

# Some of the dependencies are only available in our own repo
ADD https://packages.fein-aachen.org/redhat/fein.repo /etc/yum.repos.d/

# Dependencies
RUN dnf -y install \
	libarabica

