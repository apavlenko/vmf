import junit.framework.*;
import com.intel.vmf.MetadataStream;
import com.intel.vmf.Metadata;
import com.intel.vmf.MetadataSet;
import com.intel.vmf.MetadataDesc;
import com.intel.vmf.FieldDesc;
import com.intel.vmf.Variant;
import com.intel.vmf.Vmf;
import com.intel.vmf.MetadataSchema;

import static org.junit.Assert.*;

import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class VmfVideoSegmentTest 
{
    @BeforeClass
    public static void init()
    {
        Vmf.initialize();
    }
    
    @AfterClass
    public static void terminate()
    {
        Vmf.terminate();
    }
    
    protected MetadataStream.VideoSegment vs1;
    protected MetadataStream.VideoSegment vs2;
    
    @Before
    public void setUp ()
    {
        vs1 = new MetadataStream.VideoSegment();
        vs2 = new MetadataStream.VideoSegment("holiday", 35, 30);
    }
    
    @Test
    public void testGettersAndSetters()
    {
        System.out.println("Inside VmfVideoSegmentTest.testGettersAndSetters()");
        
        assertEquals ("holiday", vs2.getTitle());
        assertEquals ("", vs1.getTitle ());
        
        vs1.setTitle ("travel");
        assertEquals ("", vs1.getTitle ());
        
        assertEquals (0, vs1.getFPS ());
        assertEquals (35, vs2.getFPS ());
        
        vs1.setFPS (30);
        assertEquals (30, vs1.getFPS ());
        
        assertEquals (0, vs1.getDuration ());
        assertEquals (0, vs2.getDuration ());
        
        vs1.setDuration (10);
        vs2.setDuration (20);
        
        assertEquals (10, vs1.getDuration ());
        assertEquals (20, vs2.getDuration ());
        
        assertEquals (-1, vs1.getTime ());
        assertEquals (30, vs2.getTime ());
        
        vs1.setTime (0);
        assertEquals (0, vs1.getTime ());
        
        assertEquals (0, vs1.getWidth ());
        assertEquals (0, vs1.getHeight ());
        
        assertEquals (0, vs2.getWidth ());
        assertEquals (0, vs2.getHeight ());
        
        vs1.setResolution (1280, 720);
        vs2.setResolution (1360, 768);
        
        assertEquals (1280, vs1.getWidth ());
        assertEquals (720, vs1.getHeight ());
        
        assertEquals (1360, vs2.getWidth ());
        assertEquals (768, vs2.getHeight ());
    }
 }