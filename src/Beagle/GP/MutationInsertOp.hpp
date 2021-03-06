/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   beagle/GP/MutationInsertOp.hpp
 *  \brief  Definition of the class GP::MutationInsertOp.
 *  \author Christian Gagne
 *  $Revision: 1.6 $
 *  $Date: 2007/08/08 19:26:35 $
 */

#ifndef Beagle_GP_MutationInsertOp_hpp
#define Beagle_GP_MutationInsertOp_hpp

#include <string>

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/EC/MutationOp.hpp"
#include "Beagle/Core/UInt.hpp"
#include "Beagle/Core/Float.hpp"
#include "Beagle/Core/Bool.hpp"
#include "Beagle/GP/Context.hpp"
#include "Beagle/GP/Individual.hpp"


namespace Beagle
{
namespace GP
{

/*!
 *  \class MutationInsertOp beagle/GP/MutationInsertOp.hpp "beagle/GP/MutationInsertOp.hpp"
 *  \brief GP insert mutation operator class, insert a branch in the tree.
 *  \ingroup GPF
 *  \ingroup GPOp
 *
 *  This operator mutate a GP tree by inserting a new branch at a random position in a tree,
 *  using the original subtree at this position as one argument, and if necessary randomly
 *  selecting terminal primitives to complete the arguments of the inserted node.
 */
class MutationInsertOp : public Beagle::EC::MutationOp
{

public:

	//! GP::MutationInsertOp allocator type.
	typedef AllocatorT<MutationInsertOp,Beagle::EC::MutationOp::Alloc>
	Alloc;
	//! GP::MutationInsertOp handle type.
	typedef PointerT<MutationInsertOp,Beagle::EC::MutationOp::Handle>
	Handle;
	//! GP::MutationInsertOp bag type.
	typedef ContainerT<MutationInsertOp,Beagle::EC::MutationOp::Bag>
	Bag;

	explicit MutationInsertOp(std::string inMutationPbName="gp.mutinsert.indpb",
	                          std::string inName="GP-MutationInsertOp");
	virtual ~MutationInsertOp()
	{ }

	virtual void registerParams(Beagle::System& ioSystem);
	virtual bool mutate(Beagle::Individual& ioIndividual, Beagle::Context& ioContext);

protected:

	Beagle::UInt::Handle mMaxTreeDepth;    //!< Maximum allowed tree depth.
	Beagle::UInt::Handle mNumberAttempts;  //!< Maximum number of attempts.

};

}
}

#endif // Beagle_GP_MutationInsertOp_hpp
