/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with dynamic code generation of a
    OutputFilter functionObject.

SourceFiles
    functionObjectTemplate.C

\*---------------------------------------------------------------------------*/

#ifndef codedFunctionObjectTemplate_H
#define codedFunctionObjectTemplate_H

#include "regionFunctionObject.H"

//{{{ begin codeInclude
#line 28 "/home/cfd/OpenFOAM/cfd-12/run/insituLeaching2D/system/functions/mixingQualityCheck"
#include "volFields.H"
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of classes
class fvMesh;

/*---------------------------------------------------------------------------*\
                         A templated functionObject
\*---------------------------------------------------------------------------*/

class mixingQualityCheckFunctionObject
:
    public functionObjects::regionFunctionObject
{
    // Private Data

//{{{ begin codeData
        
//}}} end codeData


    // Private Member Functions

        const fvMesh& mesh() const;


public:

    //- Runtime type information
    TypeName("mixingQualityCheck");


    // Constructors

        //- Construct from Time and dictionary
        mixingQualityCheckFunctionObject
        (
            const word& name,
            const Time& runTime,
            const dictionary&
        );

        //- Disallow default bitwise copy construction
        mixingQualityCheckFunctionObject(const mixingQualityCheckFunctionObject&) = delete;


    //- Destructor
    virtual ~mixingQualityCheckFunctionObject();


    // Member Functions

        //- Read the system calls
        virtual bool read(const dictionary&);

        //- Return the list of fields required
        virtual wordList fields() const;

        //- Execute the "executeCalls" at each time-step
        virtual bool execute();

        //- Execute the "endCalls" at the final time-loop
        virtual bool end();

        //- Write, execute the "writeCalls"
        virtual bool write();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const mixingQualityCheckFunctionObject&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

