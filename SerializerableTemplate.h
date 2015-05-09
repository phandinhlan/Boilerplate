/* [[[cog
import cog
import xml.etree.ElementTree as ET
definition = ET.parse( definitionFile )
root = definition.getroot()
name = root.attrib[ "name" ]
declaretype = root.attrib[ "declaretype" ]

cog.out( "%s " % declaretype )
cog.outl( "%s" % name )
cog.outl( "{" )
for child in root:
    if ( "Member" == child.tag ):
        cog.out( "    %s " % child.attrib[ "declaretype" ] )
        cog.outl( "    %s;" % child.attrib[ "name" ] )
]]] */
// [[[end]]]
    uint8_t* Serialize( uint8_t* Buffer )
    {
        /* [[[cog
        for child in root:
            if ( "Member" == child.tag ):
                memberName = child.attrib[ "name" ]
                memberType = child.attrib[ "type" ]
                if ( "basic" == memberType  ):
                    size = child.attrib[ "size" ]
                    if ( "1" == size ):
                        cog.outl( "*Buffer++ = %s;" % memberName )
                    elif ( "2" == size ):
                        cog.outl( "*Buffer++ = (%s >> 8) & 0xff;" % memberName )
                        cog.outl( "*Buffer++ = (%s & 0xff);" % memberName )
                    elif ( "4" == size ):
                        cog.outl( "*Buffer++ = (%s >> 24) & 0xff;" % memberName ) 
                        cog.outl( "*Buffer++ = (%s >> 16) & 0xff;" % memberName )
                        cog.outl( "*Buffer++ = (%s >> 8) & 0xff;" % memberName )
                        cog.outl( "*Buffer++ = (%s & 0xff);" % memberName )
                elif ( "serializable" == memberType ):
                    cog.outl( "Buffer = %s.Serialize( Buffer );" %memberName )
        ]]] */
        // [[[end]]]

        return( Buffer );
    }

    uint8_t* Deserialize( uint8_t* Buffer )
    {
        /* [[[cog
        for child in root:
            if ( "Member" == child.tag ):
                memberName = child.attrib[ "name" ]
                memberType = child.attrib[ "type" ]
                if ( "basic" == memberType  ):
                    size = child.attrib[ "size" ]
                    if ( "1" == size ):
                        cog.outl( "%s = *Buffer++;" % memberName )
                    elif ( "2" == size ):
                        cog.outl( "%s = (Buffer[ 0 ] << 8) | Buffer[ 1 ];" % memberName )
                        cog.outl( "Buffer += 2;" )
                    elif ( "4" == size ):
                        cog.outl( "%s = (Buffer[ 0 ] << 24) | (Buffer[ 1 ] << 16) | (Buffer[ 2 ] << 8) | Buffer[ 3 ];" % memberName )
                        cog.outl( "Buffer += 4;" )
                elif ( "serializable" == memberType ):
                    cog.outl( "Buffer = %s.Deserialize( Buffer );" %memberName )
        ]]] */
        // [[[end]]]

        return( Buffer );
    }
};